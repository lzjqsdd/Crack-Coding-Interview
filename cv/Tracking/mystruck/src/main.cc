/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * main.cc
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

#include <iostream>
#include <fstream>
#include "cv.h"
#include "highgui.h"
#include "track.h"

using namespace std;

void TrackFromFile();
//读取配置文件
Config m_config; //这个文件以后作为全局，主要传递m_initbb;

int main(int agrc,char **argv)
{	
	TrackFromFile();
}

void TrackFromFile()
{
    IplImage *img;
    IplImage *grayimg;

    string filename;
    ifstream myfile(m_config.imgpath.c_str());
    if (myfile)
    {
		getline(myfile,filename); //先拿初始的版本以及gt
		string init_imgpath = m_config.basepath+filename;
        img = cvLoadImage(init_imgpath.c_str());//加载第一个图片
		
		ifstream gtfile(m_config.gtpath.c_str()); //groudtruth文件
		if(gtfile)
		{
			string gtdata;
			getline(gtfile,gtdata);
			float xmin,ymin,width,height; //从gt读到的bb的大小
			sscanf(gtdata.c_str(),"%f\t%f\t%f\t%f",&xmin,&ymin,&width,&height);
			float scaleX = m_config.width*1.0/img->width; //因为对图像归一化，所以BoundingBox也要按比例缩放
			float scaleY = m_config.height*1.0/img->height;
			cout<<scaleX<<endl<<scaleY<<endl;
			m_config.m_initbb = cvRect(xmin*scaleX,ymin*scaleY,width*scaleX,height*scaleY);
		}
		else
			cout<<"未找到groundTruth数据路径"<<endl;


		Track tracker(m_config);
		
        while (getline( myfile, filename ))
        {
			string imgpath = m_config.basepath+filename;
            img = cvLoadImage(imgpath.c_str());
            if(img==NULL) break;
			tracker.track (img); //传递读取的原始图片
            cvWaitKey(100);
        }
        myfile.close();
    }
    cvReleaseImage(&img);
    cvDestroyWindow("File");
}

