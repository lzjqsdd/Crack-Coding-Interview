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
#include "Config.h"
#include "ImgProcess.h"

using namespace std;

void TrackFromFile(const char *path);
//读取配置文件
Config m_config;

int main(int agrc,char **argv)
{	
	TrackFromFile(m_config.imgpath.c_str());
}

void TrackFromFile(const char *path)
{
    IplImage *img;
    IplImage *grayimg;

    string filename;
    ifstream myfile(path);
	cout<<path<<endl;
    if (myfile)  // same as: if (myfile.good())
    {
        cvNamedWindow("File");
        while (getline( myfile, filename ))  // same as: while (getline( myfile, line ).good())
        {
			string imgpath = m_config.basepath+filename;
            img = cvLoadImage(imgpath.c_str());
            if(img==NULL) break;
			
            grayimg = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,1);
            cvCvtColor(img,grayimg,CV_RGB2GRAY);
            cvShowImage("File",grayimg);
            cvWaitKey(100);
        }
        myfile.close();
    }
    cvReleaseImage(&img);
    cvDestroyWindow("File");
}


