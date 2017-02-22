#ifndef DEMOIMAGE_H
#define DEMOIMAGE_H
#include <iostream>
#include <string>
#include "opencv2/highgui.hpp"
#include "opencv2/ml.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <ml.h>
#include "cv.h"
#include "dirent.h"
#include "fstream"
#include "string"

using namespace std;
using namespace cv;

class DemoImage
{
public:
    DemoImage();
    ~DemoImage();
    IplImage* img;
    CvCapture *capture;

    //basic function
    void LoadImage(const char * path);
    void ShowImage();
    void PlayVideo(const char *name);
    void PlayVideoWithSlideBar(const char*name);
    void PlayVideoFromFile(const char *path,const char *outfile);
    void ShowCamera();
    void onTrackbarSlide(int pos);
    void cvText(IplImage* img, const char* text, int x, int y);
    IplImage * resizeImage(IplImage *src);
    IplImage *resizeImageScale(IplImage *src,float scale);
    void write2file(const char *name,vector<float> data,int label);
    string& trim(string &s);
    void split1(string& s, string& delim,vector< string >& ret);

    //io function
    char ** getAllFile(const char *folder);


    //picture convert
    void rgb2gray(IplImage *src,IplImage *dst);

    //for hog feature extract
    vector<float> ExtractFeatrure(IplImage *src,int binsize,int cellsize,int blocksize,
                                  int label,const char * outfile,bool write = true);
    void ExtractFeatrureFromFile(const char *path,const char *outfile,int label);
    void train(const char *pospath,int posnum,const char *negpath,int negnum);
    void detect(const char *filename);
    void detectFromFile(const char *path);
};

#endif // DEMOIMAGE_H
