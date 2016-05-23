/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * sampler.cc
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

#include "sampler.h"


vector<CvRect> Sampler::RaidalSamples(CvRect TSample,int r,int nr,int nt)
{
	vector<CvRect> samples;
	samples.push_back(TSample); //先加入正样本（中心位置）
	float rstep = (float)r/nr; //极方向步长
	float tstep = (float)M_PI/nt; //旋转角度步长
	CvRect sample(TSample); //其他采样的大小,左上角可变，宽高和TSample一致
	for(int ir=1;ir<=nr;ir++)
	{
		float phase = (ir%2)*tstep/2;
		for(int it=0;it<nt;it++)
		{
			float dx = ir*rstep*cosf(it*tstep+phase);
			float dy = ir*rstep*sinf(it*tstep+phase);
			sample.x = TSample.x+dx;
			sample.y = TSample.y+dy;
			samples.push_back(sample);
		}
	}
}


vector<CvRect> Sampler::CircleSamples(CvRect TSample,int r)
{
	vector<CvRect> samples;
	samples.push_back(TSample); //先加入正样本（中心位置）
	CvRect sample(TSample); //其他采样的大小,左上角可变，宽高和TSample一致
	for(int ix = -r;ix<=r;ix++)
		for(int iy = -r;iy<=r;iy++)
		{
			if(ix*ix+iy*iy > r*r) continue; //不在圆内
			if(ix==0&&iy==0) continue;//在中心处，已经加入
			sample.x = TSample.x+ix;
			sample.y = TSample.y+iy;
			samples.push_back(sample);
		}   
}   
