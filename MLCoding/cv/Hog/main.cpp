#include <QCoreApplication>
#include <opencv2/opencv.hpp>
#include "demoimage.h"
using namespace cv;
using namespace ml;

int main(int argc, char *argv[])
{
    DemoImage di;
//    di.LoadImage("lena.jpg");
//    di.ShowImage();

//    di.PlayVideo("data/video.mp4");
//    di.ShowCamera();
//   di.PlayVideoFromFile("/home/lzjqsdd/Project/opencvDemo/data/INRIAPerson/train_64x128_H96/pos.lst");
  //  di.PlayVideo("video.mp4");
 //  di.LoadImage("lena.jpg");
//   di.ExtractFeatrure(di.resizeImage(di.img),9,8,16,8);

 //    di.train("data1.txt",1);
 //   di.ExtractFeatrureFromFile("pos.lst","fdata",1);
 //   di.ExtractFeatrureFromFile("neg.lst","fdata",-1);

 //   di.train("fdata",0,"neg.txt",0);
 //   di.detect("test.jpg");
 //   di.detectFromFile("tneg.lst");
 //   di.detectFromFile("tpos.lst");
    di.detectFromFile(argv[1]);
}
