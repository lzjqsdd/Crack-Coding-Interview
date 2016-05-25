/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * floatrect.h
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

#ifndef _FLOATRECT_H_
#define _FLOATRECT_H_
#include <iostream>
using namespace std;

class FloatRect
{
public:
	float x;
	float y;
	float width;
	float height;
	float maxx;
	float maxy;

	FloatRect();
	FloatRect(float x,float y,float width,float height);
	FloatRect(const FloatRect& rect);
	float Overlap(FloatRect &rect2); //计算两个重叠
	bool isInside(FloatRect &rect);
	inline float Area() const { return width * height; } //计算面积,用于haar特征归一化	
	inline void Translate(float tx, float ty) { x += tx; y += ty; } //水平平移x,竖直平移y
	void show();

protected:

private:

};

#endif // _FLOATRECT_H_

