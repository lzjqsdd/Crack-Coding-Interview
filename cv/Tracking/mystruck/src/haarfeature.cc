/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * haarfeature.cc
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

#include "haarfeature.h"


#include <cassert>
#include <iostream>

using namespace std;

HaarFeature::HaarFeature(FloatRect bb,int type)
{
	//这里的CvRect可能需要改为Float，这里表示的是比例
	m_bb = bb; //每个样本位置以bb表示。
	
	switch (type)
	{
	case 0:
		{
			m_rects.push_back(FloatRect(bb.x, bb.y, bb.width, bb.height/2));
			m_rects.push_back(FloatRect(bb.x, bb.y+bb.height/2, bb.width, bb.height/2));
			m_weights.push_back(1.f);
			m_weights.push_back(-1.f);
			m_factor = 255*1.f/2;
			break;
		}
	case 1:
		{
			m_rects.push_back(FloatRect(bb.x, bb.y, bb.width/2, bb.height));
			m_rects.push_back(FloatRect(bb.x+bb.width/2, bb.y, bb.width/2, bb.height));
			m_weights.push_back(1.f);
			m_weights.push_back(-1.f);
			m_factor = 255*1.f/2;
			break;
		}
	case 2:
		{
			m_rects.push_back(FloatRect(bb.x, bb.y, bb.width/3, bb.height));
			m_rects.push_back(FloatRect(bb.x+bb.width/3, bb.y, bb.width/3, bb.height));
			m_rects.push_back(FloatRect(bb.x+2*bb.width/3, bb.y, bb.width/3, bb.height));
			m_weights.push_back(1.f);
			m_weights.push_back(-2.f);
			m_weights.push_back(1.f);
			m_factor = 255*2.f/3;
			break;
		}
	case 3:
		{
			m_rects.push_back(FloatRect(bb.x, bb.y, bb.width, bb.height/3));
			m_rects.push_back(FloatRect(bb.x, bb.y+bb.height/3, bb.width, bb.height/3));
			m_rects.push_back(FloatRect(bb.x, bb.y+2*bb.height/3, bb.width, bb.height/3));
			m_weights.push_back(1.f);
			m_weights.push_back(-2.f);
			m_weights.push_back(1.f);
			m_factor = 255*2.f/3;
			break;
		}
	case 4:
		{
			m_rects.push_back(FloatRect(bb.x, bb.y, bb.width/2, bb.height/2));
			m_rects.push_back(FloatRect(bb.x+bb.width/2, bb.y+bb.height/2, bb.width/2, bb.height/2));
			m_rects.push_back(FloatRect(bb.x, bb.y+bb.height/2, bb.width/2, bb.height/2));
			m_rects.push_back(FloatRect(bb.x+bb.width/2, bb.y, bb.width/2, bb.height/2));
			m_weights.push_back(1.f);
			m_weights.push_back(1.f);
			m_weights.push_back(-1.f);
			m_weights.push_back(-1.f);
			m_factor = 255*1.f/2;
			break;
		}
	case 5:
		{
			m_rects.push_back(FloatRect(bb.x, bb.y, bb.width, bb.height));
			m_rects.push_back(FloatRect(bb.x+bb.width/4, bb.y+bb.height/4, bb.width/2, bb.height/2));
			m_weights.push_back(1.f);
			m_weights.push_back(-4.f);
			m_factor = 255*3.f/4;
			break;
		}				
	}
}

HaarFeature::~HaarFeature()
{
	
}


//这个函数计算每个样本的所有的haar特征的值（只是比例）
float HaarFeature::Eval(IplImage *image,FloatRect roi)
{
	float value = 0.f;
	for (int i = 0; i < (int)m_rects.size(); ++i)
	{
		FloatRect r  = m_rects[i];
		CvRect sampleRect = cvRect((int)(roi.x+r.x*roi.width+0.5f),(int)(roi.y+r.y*roi.height+0.5f),
		                           (int)(r.width*roi.width),(int)(r.height*roi.height)
		                           );
		value += m_weights[i]*sum(image,roi);
	}
	//cout<<"value:"<<value<<endl;
	return value / (m_factor*roi.Area()*m_bb.Area());
}


int HaarFeature::sum(IplImage *img,FloatRect rect)
{
	assert(rect.x>= 0 && rect.y>= 0 && rect.maxx<= img->width && rect.y <= img->height);
	int result = cvGet2D(img,rect.y,rect.x).val[0]+
		cvGet2D(img,rect.maxy,rect.maxx).val[0] - 
		cvGet2D(img,rect.maxy,rect.x).val[0] - 
		cvGet2D(img,rect.y,rect.maxx).val[0];
	return result;
}
