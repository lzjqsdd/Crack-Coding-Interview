/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * track.cc
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

#include "track.h"
#include <climits>

Track::Track(Config config)
{
	m_config = config; //传递进来的conif
	m_bb = config.m_initbb;
	m_learner = LaRank();
}
void Track::track(IplImage *src) //计算当前帧目标的最可能的位置,参数为3通道原始图像
{
	//step1:预处理得到单通道归一化的图片
	m_img = preprocess(src); 
	//step2:以m_img为中心采样
	vector<FloatRect> rects = Sampler::CircleSamples(m_bb,m_config.searchR);
	//step3:去除越界的位置
	vector<FloatRect> keptRects;
	FloatRect srcRect = FloatRect(0,0,m_img->width,m_img->height);
	for(int i=0;i<rects.size();i++)
	{
		if(rects[i].isInside(srcRect))
		   keptRects.push_back(rects[i]);
	}
	//cout<<rects.size()<<":"<<keptRects.size()<<endl;
	//step3:对剩余采样的每个样本计算得分
	vector<float> scores;
	m_learner.Eval (m_img,keptRects,scores); //得到不同采样位置的分数
	cout<<"scores.size:"<<scores.size()<<endl;
	//step4:选择最大的那个
	float maxscore = FLT_MIN;
	int maxind = -1; //记录最大的那个框框的编号
	for(int i=0;i<keptRects.size();i++)
	{
		if(maxscore < scores[i])
		{
			maxscore = scores[i];
			maxind = i;
		}
	}
	if(maxind!=-1) //如果存在最大的
	{
		m_bb = keptRects[maxind];
		UpdateLearner(src,m_bb);
	}
	draw(c_img,m_bb);
}


IplImage* Track::preprocess(IplImage *src)
{
	IplImage *dst = cvCreateImage(cvSize(m_config.width,m_config.height),src->depth,src->nChannels);
	cvResize(src,dst,CV_INTER_LINEAR);
	c_img = dst; //归一化图像保存给c_img，用于画图
    IplImage *grayimg = cvCreateImage(cvGetSize(dst),IPL_DEPTH_8U,1);
    cvCvtColor(dst,grayimg,CV_RGB2GRAY); //转换为灰度图
	return grayimg;
}


void Track::draw(IplImage *img,FloatRect m_bb)
{
	CvPoint leftup_point = cvPoint(m_bb.x,m_bb.y);
	CvPoint rightdown_point = cvPoint(m_bb.x+m_bb.width,m_bb.y+m_bb.height);
	//cout<<m_bb.x<<endl;
	cvRectangle(img,leftup_point,rightdown_point,CV_RGB(255,0,0));
	cvShowImage("Tracker",img);
}
void Track::UpdateLearner(IplImage *img,FloatRect bb)
{
	
}


