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

LaRank::LaRank()
{
	m_kernel = GuassianKernel(0.2);
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
		cout<<"scores"<<i<<":"<<scores[i]<<endl;
	}
}

pair<int,double> LaRank::MinGradient(int ind)
{
	
}
