#include <iostream>
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "cv.h"
#include "ImgProcess.h"

using namespace std;


int main(int agrc,int **argv)
{
	//读取配置文件
	Config m_config;
	
	//根据配置文件读取图片
	int m_width = m_config.width;
	int m_height = m_config.height;

	TrackFromFile(m_config.imgpath);

}

void DemoImage::TrackFromFile(const char *path)
{
    IplImage *img;
    IplImage *grayimg;

    string filename;
    ifstream myfile(path);
    if (myfile)  // same as: if (myfile.good())
    {
        cvNamedWindow("File");
        while (getline( myfile, filename ))  // same as: while (getline( myfile, line ).good())
        {
            //     filename = folder +filename;
            img = cvLoadImage(filename.c_str());
            if(img==NULL) break;
            //zhuanhuanweihuidutu
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
