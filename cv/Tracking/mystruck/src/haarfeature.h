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
#include <iostream>
#include <vector>
using namespace std;
class HaarFeature
{
public:
	HaarFeature(CvRect bb,int type);
	~HaarFeature();
	floatRect m_bb;
	vector<CvRect> m_rects;
	vector<float> m_weights;
	float m_factor;

	float Eval(IplImage *image,CvRect roi);
	int sum(IplImage *img,CvRect rect);

	typedef struct floatRect
	{
		float x,y;
		float width,height;
	}floatRect;
protected:

private:

};

#endif // _HAARFEATURE_H_

