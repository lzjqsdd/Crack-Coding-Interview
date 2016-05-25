/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * haarfeatures.h
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

#ifndef _HAARFEATURES_H_
#define _HAARFEATURES_H_
#include "haarfeature.h"
#include <Eigen/Core>
using namespace Eigen;
//这个类主要表示对于某一个样本的haar的192为特征的值。
class HaarFeatures
{
public:
//	vector<HaarFeature> m_features; //存放192维向量(HaarFeature类对象)
	Eigen::VectorXd m_featVec; //用来存放最终算好的192维Haar特征（计算的每一维的值），
	vector<HaarFeature> getHaarFeature(); //计算每个sample的Haar特征

	Eigen::VectorXd& EvalSingleSample(IplImage *img,FloatRect rect); //计算192特征，保存到m_featVec;

};

#endif // _HAARFEATURES_H_

