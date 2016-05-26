/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * larank.cc
 * Copyright (C) 2016 lzjqsdd <lzjqsdd@163.com>
 *
 * mystruck is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * mystruck is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "larank.h"


static const int kTileSize = 30;
static const int kMaxSVs = 2000;
LaRank::LaRank()
{
	m_C = 100;
	m_kernel = GuassianKernel(0.2);
	m_K = MatrixXd::Zero(100,100);
}

double LaRank::Evaluate(const Eigen::VectorXd& x)
{
	//这里y没有用到哎。。。对应公式9下面正文第二行
	double f = 0.0;
	for (int i = 0; i < (int)m_svs.size(); ++i)
	{
		const SupportVector& sv = *m_svs[i];
		f += sv.b*m_kernel.Eval(x, sv.x->x[sv.y]);
	}
	return f;
}

//这个函数用来计算不同位置的可能性大小
void LaRank::Eval(IplImage *img,vector<FloatRect> rects,vector<float>& scores)
{
	FloatRect& center(rects[0]); //先拿到前一帧的目标位置
	//采样
	vector<Eigen::VectorXd> fvs;
	m_features.EvalAllSample (img,rects,fvs);
	scores.resize(fvs.size());
	for (int i = 0; i < (int)fvs.size(); ++i)
	{
		// express y in coord frame of centre sample
		FloatRect y(rects[i]);
		y.Translate (-center.x,-center.y);
		scores[i] = Evaluate(fvs[i]);
		//cout<<"scores"<<i<<":"<<scores[i]<<endl;
	}
}

pair<int,double> LaRank::MinGradient(int ind)
{
	SupportPattern* sp = m_sps[ind];
	pair<int, double> minGrad(-1, DBL_MAX);
	for (int i = 0; i < (int)sp->yv.size(); ++i)
	{
	//	double grad = -Loss(sp->yv[i], sp->yv[sp->y]) - Evaluate(sp->x[i], sp->yv[i]);
		double grad = -Loss(sp->yv[i], sp->yv[sp->y]) - Evaluate(sp->x[i]);
		if (grad < minGrad.second)
		{
			minGrad.first = i;
			minGrad.second = grad;
		}
	}
	return minGrad;
}

void LaRank::Update(IplImage *img,vector<FloatRect> rects, int y)
{
	SupportPattern*sp = new SupportPattern;
//	vector<FloatRect>& rects = sample.GetRects();
	FloatRect center = rects[y];
	for(int i=0;i<(int)rects.size();i++)
	{
		FloatRect r = rects[i];
		r.Translate (-center.x,-center.y); //平移量
		sp->yv.push_back(r);
	}	

	sp->x.resize(rects.size());
	m_features.EvalAllSample (img,rects,sp->x);
	sp->y = y;
	sp->refCount = 0;
	m_sps.push_back(sp);


	//更新参数
	ProcessNew ((int)m_sps.size()-1);
	BudgetMaintenance();
	for(int i=0;i<10;i++)
	{
		Reprocess();
		BudgetMaintenance();
	}
}


void LaRank::Reprocess()
{
	ProcessOld();
	for (int i = 0; i < 10; ++i)
	{
		Optimize();
	}
}

void LaRank::BudgetMaintenance()
{
	while((int)m_svs.size() > 100)
		BudgetMaintenance ();
}

//把当前帧的目标位置作为正样本，然后从其他中间找到使梯度g(y_i)最小的作为负样本
void LaRank::ProcessNew(int ind) //ind是最后的m_sps中最后的那个向量的索引
{
	//cout<<"PrcessNew:"<<ind<<"==m_sps->y:"<<m_sps[ind]->y<<endl;
	// gradient is -f(x,y) since loss=0,(loss=0是因为这个样本就是目标位置，yi==y,完全重叠）
	//int ip = AddSupportVector(m_sps[ind], m_sps[ind]->y, -Evaluate(m_sps[ind]->x[m_sps[ind]->y],m_sps[ind]->yv[m_sps[ind]->y]));
	int ip = AddSupportVector(m_sps[ind], m_sps[ind]->y, -Evaluate(m_sps[ind]->x[m_sps[ind]->y]));
	pair<int, double> minGrad = MinGradient(ind);
	int in = AddSupportVector(m_sps[ind], minGrad.first, minGrad.second);

	SMOStep(ip, in);
}


//从已有的support pattern中随机选择一个x_i，找到使梯度最大的y，作为正样本，负样本同上述一样
void LaRank::ProcessOld()
{
	if (m_sps.size() == 0) return;

	// choose pattern to process
	int ind = rand() % m_sps.size();

	// find existing sv with largest grad and nonzero beta
	int ip = -1;
	double maxGrad = -DBL_MAX;
	for (int i = 0; i < (int)m_svs.size(); ++i)
	{
		if (m_svs[i]->x != m_sps[ind]) continue;

		const SupportVector* svi = m_svs[i];
		if (svi->g > maxGrad && svi->b < m_C*(int)(svi->y == m_sps[ind]->y)) //满足s.t.
		{
			ip = i;
			maxGrad = svi->g;
		}
	}
	assert(ip != -1);
	if (ip == -1) return;

	// find potentially new sv with smallest grad
	pair<int, double> minGrad = MinGradient(ind);
	int in = -1;
	for (int i = 0; i < (int)m_svs.size(); ++i)
	{
		if (m_svs[i]->x != m_sps[ind]) continue;

		if (m_svs[i]->y == minGrad.first)
		{
			in = i;
			break;
		}
	}
	if (in == -1)
	{
		// add new sv
		in = AddSupportVector(m_sps[ind], minGrad.first, minGrad.second);
	}

	SMOStep(ip, in);
}

int LaRank::AddSupportVector(SupportPattern* x, int y, double g)
{
	SupportVector* sv = new SupportVector;
	sv->b = 0.0;
	sv->x = x;
	sv->y = y;
	sv->g = g;

	int ind = (int)m_svs.size();
	m_svs.push_back(sv);
	x->refCount++;

	// update kernel matrix
	for (int i = 0; i < ind; ++i)
	{
		m_K(i,ind) = m_kernel.Eval(m_svs[i]->x->x[m_svs[i]->y], x->x[y]);
		m_K(ind,i) = m_K(i,ind);
	}
	m_K(ind,ind) = m_kernel.Eval(x->x[y]);

	return ind;
}


void LaRank::SwapSupportVectors(int ind1, int ind2)
{
	SupportVector* tmp = m_svs[ind1];
	m_svs[ind1] = m_svs[ind2];
	m_svs[ind2] = tmp;
	
	VectorXd row1 = m_K.row(ind1);
	m_K.row(ind1) = m_K.row(ind2);
	m_K.row(ind2) = row1;
	
	VectorXd col1 = m_K.col(ind1);
	m_K.col(ind1) = m_K.col(ind2);
	m_K.col(ind2) = col1;
}

void LaRank::RemoveSupportVector(int ind)
{
#if VERBOSE
	cout << "Removing SV: " << ind << endl;
#endif	

	m_svs[ind]->x->refCount--;
	if (m_svs[ind]->x->refCount == 0) //如果这个支持模式不在有使用的话也移除
	{
		// also remove the support pattern
		for (int i = 0; i < (int)m_sps.size(); ++i)
		{
			if (m_sps[i] == m_svs[ind]->x)
			{
				delete m_sps[i];
				m_sps.erase(m_sps.begin()+i);
				break;
			}
		}
	}

	// make sure the support vector is at the back, this
	// lets us keep the kernel matrix cached and valid
	if (ind < (int)m_svs.size()-1)
	{
		SwapSupportVectors(ind, (int)m_svs.size()-1);
		ind = (int)m_svs.size()-1;
	}
	delete m_svs[ind];
	m_svs.pop_back();
}


void LaRank::BudgetMaintenanceRemove()
{
	// find negative sv with smallest effect on discriminant function if removed
	double minVal = DBL_MAX;
	int in = -1;
	int ip = -1;
	for (int i = 0; i < (int)m_svs.size(); ++i)
	{
		if (m_svs[i]->b < 0.0)
		{
			// find corresponding positive sv
			int j = -1;
			for (int k = 0; k < (int)m_svs.size(); ++k)
			{
				if (m_svs[k]->b > 0.0 && m_svs[k]->x == m_svs[i]->x)
				{
					j = k;
					break;
				}
			}
			double val = m_svs[i]->b*m_svs[i]->b*(m_K(i,i) + m_K(j,j) - 2.0*m_K(i,j));
			if (val < minVal)
			{
				minVal = val;
				in = i;
				ip = j;
			}
		}
	}

	// adjust weight of positive sv to compensate for removal of negative
	m_svs[ip]->b += m_svs[in]->b;

	// remove negative sv
	RemoveSupportVector(in);
	if (ip == (int)m_svs.size())
	{
		// ip and in will have been swapped during support vector removal
		ip = in;
	}
	
	if (m_svs[ip]->b < 1e-8)
	{
		// also remove positive sv
		RemoveSupportVector(ip);
	}

	// update gradients
	// TODO: this could be made cheaper by just adjusting incrementally rather than recomputing
	for (int i = 0; i < (int)m_svs.size(); ++i)
	{
		SupportVector& svi = *m_svs[i];
	//	svi.g = -Loss(svi.x->yv[svi.y],svi.x->yv[svi.x->y]) - Evaluate(svi.x->x[svi.y], svi.x->yv[svi.y]);
		svi.g = -Loss(svi.x->yv[svi.y],svi.x->yv[svi.x->y]) - Evaluate(svi.x->x[svi.y]);
	}	
}


void LaRank::Optimize()
{
	if (m_sps.size() == 0) return;
	
	// choose pattern to optimize
	int ind = rand() % m_sps.size();

	int ip = -1;
	int in = -1;
	double maxGrad = -DBL_MAX;
	double minGrad = DBL_MAX;
	for (int i = 0; i < (int)m_svs.size(); ++i)
	{
		if (m_svs[i]->x != m_sps[ind]) continue;

		const SupportVector* svi = m_svs[i];
		if (svi->g > maxGrad && svi->b < m_C*(int)(svi->y == m_sps[ind]->y))
		{
			ip = i;
			maxGrad = svi->g;
		}
		if (svi->g < minGrad)
		{
			in = i;
			minGrad = svi->g;
		}
	}
	assert(ip != -1 && in != -1);
	if (ip == -1 || in == -1)
	{
		// this shouldn't happen
		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		return;
	}

	SMOStep(ip, in);
}


void LaRank::SMOStep(int ipos, int ineg)
{
	if (ipos == ineg) return;

	SupportVector* svp = m_svs[ipos]; //正样本向量
	SupportVector* svn = m_svs[ineg];
	assert(svp->x == svn->x);
	SupportPattern* sp = svp->x;

	//cout << "SMO: gpos:" << svp->g << " gneg:" << svn->g << endl;
	if ((svp->g - svn->g) < 1e-5)
	{
		cout << "SMO: skipping" << endl;	
	}
	else
	{
		double kii = m_K(ipos, ipos) + m_K(ineg, ineg) - 2*m_K(ipos, ineg);
		double lu = (svp->g-svn->g)/kii;
		// no need to clamp against 0 since we'd have skipped in that case
		double l = min(lu, m_C*(int)(svp->y == sp->y) - svp->b);

		svp->b += l;
		svn->b -= l;

		// update gradients
		for (int i = 0; i < (int)m_svs.size(); ++i)
		{
			SupportVector* svi = m_svs[i];
			svi->g -= l*(m_K(i, ipos) - m_K(i, ineg));
		}
		//cout << "SMO: " << ipos << "," << ineg << " -- " << svp->b << "," << svn->b << " (" << l << ")" << endl;	
	}
	
	// check if we should remove either sv now
	// 如果SMO中beta_i的值为0，移除这个向量
	if (fabs(svp->b) < 1e-8)
	{
		RemoveSupportVector(ipos);
		if (ineg == (int)m_svs.size())
		{
			// ineg and ipos will have been swapped during sv removal
			ineg = ipos;
		}
	}

	if (fabs(svn->b) < 1e-8)
	{
		RemoveSupportVector(ineg);
	}
}