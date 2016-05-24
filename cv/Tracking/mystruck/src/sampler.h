/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * sampler.h
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

#ifndef _SAMPLER_H_
#define _SAMPLER_H_
#include <iostream>
#include <vector>
#include "cv.h"
#include "highgui.h"
#include <cmath>
#include "floatrect.h"

using namespace std;

class Sampler
{
public:
	//按照极坐标采样,返回一系列的矩形位置
	vector<FloatRect> RaidalSamples(FloatRect TSample,int r,int nr,int nt); 
	//按照上下左右在一定圆内采样。
	vector<FloatRect> CircleSamples(FloatRect TSample,int r);
protected:

private:

};

#endif // _SAMPLER_H_

