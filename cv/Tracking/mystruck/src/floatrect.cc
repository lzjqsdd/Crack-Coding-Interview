/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * floatrect.cc
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

#include "floatrect.h"

FloatRect::FloatRect()
{
	this->x = this->y = this->width = this->height = 0;
}

FloatRect::FloatRect(float x,float y,float width,float height)
{
	this->x = x;
	this->y= y;
	this->width = width;
	this->height = height;
	this->maxx = x+width;
	this->maxy = y+height;
}

FloatRect::FloatRect(const FloatRect& rect)
{
	x = rect.x;
	y = rect.y;
	width = rect.width;
	height = rect.height;
	maxx = rect.maxx;
	maxy = rect.maxy;
}

float FloatRect::Overlap(FloatRect &rect2) //计算两个重叠
{
	float x0 = max(x,rect2.x);
    float x1 = min(maxx,rect2.maxx);
	float y0 = max(y,rect2.y);
	float y1 = min(maxy,rect2.maxy);
    
    if (x0 >= x1 || y0 >= y1) return 0.f;
    
    float areaInt = (x1-x0)*(y1-y0);
    return areaInt/((float)Area()+(float)rect2.Area()-areaInt);
}

bool FloatRect::isInside (FloatRect &rect)
{
	if(x>=rect.x&&y>=rect.y&&maxx<=rect.maxx&&maxy<=rect.maxy)
		return true;
	return false;
}

void FloatRect::show()
{
	cout<<"xmin:"<<x<<"\t"<<"ymin:"<<y<<"\t"<<"xmax:"<<maxx<<"\t"<<"ymax:"<<maxy<<endl;
}