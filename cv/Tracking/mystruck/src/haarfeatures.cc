/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * haarfeatures.cc
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

#include "haarfeatures.h"

//这个函数计算一个样本的所有的Haar特征存放到一个向量中,192维，但是每个都是一个HaarFeature。
vector<HaarFeature> HaarFeatures::getHaarFeature()
{
	vector<HaarFeature> m_features;
	m_features.clear();
	float x[] = {0.2f, 0.4f, 0.6f, 0.8f};
	float y[] = {0.2f, 0.4f, 0.6f, 0.8f};
	float s[] = {0.2f, 0.4f};
	for (int iy = 0; iy < 4; ++iy)
	{
		for (int ix = 0; ix < 4; ++ix)
		{
			for (int is = 0; is < 2; ++is)
			{
				FloatRect r(x[ix]-s[is]/2, y[iy]-s[is]/2, s[is], s[is]);
				for (int it = 0; it < 6; ++it)
				{
					m_features.push_back(HaarFeature(r,it));
				}
			}
		}
	}
	return m_features;
}

//计算单一样本的192维特征，执行该函数之前应该先得到结构性的向量m_features,再利用每一维度计算。
Eigen::VectorXd& HaarFeatures::EvalSingleSample(IplImage *img,FloatRect rect)
{
	 //存放192维向量(HaarFeature类对象)
	vector<HaarFeature> m_features = getHaarFeature();
	m_featVec = VectorXd::Zero(192);
	for(int i=0;i<192;i++)
	{
		m_featVec[i] = m_features[i].Eval (img,rect);
	}
	return m_featVec;
}

void HaarFeatures::EvalAllSample(IplImage *img,vector<FloatRect> rects,vector<Eigen::VectorXd>& featVecs)
{
	featVecs.resize(rects.size());
	for(int i=0;i<rects.size();i++)
	{
		featVecs[i] = EvalSingleSample (img,rects[i]);
	}
}


