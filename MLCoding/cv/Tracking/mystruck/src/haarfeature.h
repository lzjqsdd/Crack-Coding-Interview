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

using namespace cv;
using namespace std;
using namespace Eigen;

class HaarFeature
{
public:
	HaarFeature(FloatRect bb,int type); //type表示不同的haar特征
	~HaarFeature();
	
	FloatRect m_bb;
	vector<FloatRect> m_rects; //因为这个变量存放的是每个样本的归一的值，用浮点表示.
	vector<float> m_weights; //存放每个type的haar中小格子的权重。
	float m_factor; //表示某一个type的特征的比重
//	float Eval(IplImage *image,FloatRect roi); //其实是计算每个类型的特征的值.image应该传递积分图
	float Eval(Mat& IntegralImage,FloatRect roi); //其实是计算每个类型的特征的值.image应该传递积分图
	//int sum(IplImage *img,FloatRect rect); //这里的img应该为积分图
	int sum(Mat& m_integralImages,FloatRect rect); //这里的img应该为积分图

};

#endif // _HAARFEATURE_H_

