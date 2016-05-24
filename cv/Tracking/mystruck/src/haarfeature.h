/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * haarfeature.h
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

#ifndef _HAARFEATURE_H_
#define _HAARFEATURE_H_

#include "cv.h"
#include "highgui.h"
#include "floatrect.h"
#include <iostream>
#include <vector>
#include <Eigen/Core>
using namespace std;
using namespace Eigen;

class HaarFeature
{
public:
	HaarFeature(FloatRect bb,int type);
	~HaarFeature();
	
	FloatRect m_bb;
	vector<FloatRect> m_rects; //因为这个变量存放的是每个样本的归一的值，用浮点表示.
	vector<float> m_weights;
	float m_factor;
	float Eval(IplImage *image,FloatRect roi); //其实是计算每个类型的特征的值.
	int sum(IplImage *img,FloatRect rect);
	
	//vector<HaarFeature> m_features; //存放192维向量
	Eigen::VectorXd m_featVec; //用来存放最终算好的192维Haar特征，
	vector<HaarFeature> getFeature(); //计算每个sample的Haar特征

};

#endif // _HAARFEATURE_H_

