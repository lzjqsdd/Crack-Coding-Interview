/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * track.h
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

#ifndef _TRACK_H_
#define _TRACK_H_

#include "cv.h"
#include "highgui.h"
#include "Config.h"
#include "floatrect.h"
#include "sampler.h"
#include "larank.h"
class Track
{
public:
	Config m_config;
	FloatRect m_bb;
	LaRank m_learner;
	Track(Config config); //构造时要把m_initbb传递进来
	IplImage *c_img; //传递进来的原始图像colorImg
	IplImage *m_img; //用于存储每次处理的单通道图像
	IplImage *preprocess(IplImage *src);//转换图片为灰度图
	void track(IplImage *img); //进行预测的函数，根据前一帧的bb，采样预测
	void draw(IplImage *img,FloatRect m_bb); //根据预测的BoundingBox画出矩形框
	void UpdateLearner(IplImage *img,FloatRect bb); //根据得到的bb，再次进行采样然后更新分类器
protected:

private:

};

#endif // _TRACK_H_

