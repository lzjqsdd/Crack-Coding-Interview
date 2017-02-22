#include "demoimage.h"
DemoImage::DemoImage()
{
}

DemoImage::~DemoImage()
{
    //   if(img!=NULL)
    //       cvReleaseImage(&img);
}

void DemoImage::LoadImage(const char * path)
{
    this->img = cvLoadImage(path);
}

void DemoImage::ShowImage()
{
    cvNamedWindow("show");
    cvShowImage("show",this->img);
    cvWaitKey(0);
    cvDestroyWindow("show");
}


IplImage * DemoImage::resizeImage(IplImage *src)
{
    CvSize size = cvSize(64,128);
    cvSetImageROI(src,cvRect(16,16,size.width,size.height));
    IplImage *dst = cvCreateImage(size,src->depth,src->nChannels);
    cvCopy(src,dst);
    cvResetImageROI(src);
    return dst;
}


void DemoImage::PlayVideo(const char *name)
{
    //        cvNamedWindow("Video");
    //        capture = cvCaptureFromFile(name);
    //        IplImage *frame;
    //        while(1)
    //        {
    //            frame = cvQueryFrame(capture);
    //            if(!frame) break;
    //            cvShowImage("Video",frame);
    //            char c  =  cvWaitKey(33);
    //            if(c == 27) break;
    //        }
    //        cvReleaseCapture(&capture);
    //        cvReleaseImage(&frame);
    //        cvDestroyWindow("Video");

    VideoCapture capture;
    capture.open(name);
    while(capture.isOpened())
    {
        Mat frame;
        capture>>frame;
        if(!frame.empty())
        {
            imshow("readvideo",frame);

        }
        waitKey(33);
        cout<<"hahha"<<endl;
    }
}

void DemoImage::PlayVideoWithSlideBar(const char *name)
{
    cvNamedWindow("Video");
    capture = cvCreateFileCapture(name);
    int g_slider_position = 0;

    int frames = (int)cvGetCaptureProperty(capture,CV_CAP_PROP_FRAME_COUNT);
    if(frames!=0)
    {
        cvCreateTrackbar("Position","Demo",&g_slider_position,frames,NULL);
    }

    IplImage *frame;
    while(1)
    {
        frame = cvQueryFrame(capture);
        if(!frame) break;
        cvShowImage("Video",frame);
        char c  =  cvWaitKey(33);
        if(c == 27) break;
        g_slider_position++;
    }
    cvReleaseCapture(&capture);
    cvReleaseImage(&frame);
    cvDestroyWindow("Video");

}

void DemoImage::PlayVideoFromFile(const char *path,const char*outfile)
{
    IplImage *img;
    IplImage *grayimg;

    string filename;
    //    string folder = "../data/INRIAPerson/train_64x128_H96/";
    //ifstream myfile("pos.lst");
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

void DemoImage::ShowCamera()
{
    cvNamedWindow("Camera");
    CvCapture* capture = cvCreateCameraCapture(0);
    IplImage *frame;
    while(1)
    {
        frame = cvQueryFrame(capture);
        if(!frame) break;
        cvShowImage("Video",frame);
        char c  =  cvWaitKey(33);
        if(c == 27) break;
    }
    cvReleaseCapture(&capture);
    cvReleaseImage(&frame);
    cvDestroyWindow("Camera");
}


//void DemoImage::rgb2gray(IplImage *src, IplImage *dst)
//{
//    dst  = cvCreateImage(cvGetSize(src), IPL_DEPTH_8U, 1);
//    cvCvtColor(src,dst,CV_RGB2GRAY);
//}


vector<float> DemoImage::ExtractFeatrure(IplImage *src,int binsize,int cellsize,int blocksize,
                                         int label,const char *outfile,bool write)
{
    IplImage *dst;
    vector<float> hog;

    //step1: convert to gray

    dst  = cvCreateImage(cvGetSize(src), IPL_DEPTH_8U, 1);
    cvCvtColor(src,dst,CV_RGB2GRAY);

    //step2: gamma compress
    //Nothing;

    //step3:calculate grident and arc
    int x = src->width;
    int y = src->height;

    CvMat *grad = cvCreateMat(x,y,CV_32FC1);
    CvMat *arc = cvCreateMat(x,y,CV_32FC1);

    for(int i=0;i<x;i++)
        for(int j=0;j<y;j++)
        {
            int tempX = dst->imageData[i*dst->widthStep+j+1] - dst->imageData[i*dst->widthStep+j];
            int tempY = dst->imageData[(i+1)*dst->widthStep+j] - dst->imageData[i*dst->widthStep+j];
            double temp_g = cvSqrt((double)(tempX*tempX+tempY*tempY));
            double temp_arc = cvFastArctan((float)tempY,(float)tempX);
            cvSet2D(grad,i,j,temp_g);
            if(temp_arc>=180)
                temp_arc -= 180;
            cvSet2D(arc,i,j,temp_arc);
        }


    //calc cell
    int xcellnum = x/cellsize;
    int ycellnum = y/cellsize;
    float cell[xcellnum][ycellnum][binsize];
    memset(cell,0,sizeof(cell));

    for(int i=0;i<x;i++)
        for(int j=0;j<y;j++)
        {
            int binindex = cvGet2D(arc,i,j).val[0]/20;
            int weight = cvGet2D(grad,i,j).val[0];
            cell[i/cellsize][j/cellsize][binindex] += weight;
        }


    //normalization
    for(int i=0;i<xcellnum-1;i++)
        for(int j=0;j<ycellnum-1;j++)
        {
            vector<float> block;
            for(int k=0;k<binsize;k++) block.push_back(cell[i][j][k]);
            for(int k=0;k<binsize;k++) block.push_back(cell[i+1][j][k]);
            for(int k=0;k<binsize;k++) block.push_back(cell[i][j+1][k]);
            for(int k=0;k<binsize;k++) block.push_back(cell[i+1][j+1][k]);
            normalize(block, block, 1.0, 0.0, NORM_L2);
            vector<float>::iterator it;
            for(it = block.begin();it!=block.end();it++)
            {
                hog.push_back(*it);
            }
        }
    if(write)
        write2file(outfile,hog,label);
    return hog;
}



void DemoImage::ExtractFeatrureFromFile(const char *path, const char *outfile, int label)
{
    IplImage *img;
    IplImage *grayimg;

    string filename;
    ifstream myfile(path);
    if (myfile)
    {
        cvNamedWindow("Train");
        while (getline( myfile, filename ))
        {
            img = cvLoadImage(filename.c_str());
            if(img==NULL) break;
            //zhuanhuanweihuidutu
            IplImage *dst = resizeImage(img);

            cvShowImage("Train",dst);
            ExtractFeatrure(dst,9,8,16,label,outfile);
            cvWaitKey(100);
        }
        myfile.close();
    }
    cvReleaseImage(&img);
    cvDestroyWindow("Train");
}

void DemoImage::write2file(const char *name, vector<float> data,int label)
{
    ofstream file;
    file.open(name,ios::app);
    vector<float>::iterator it;
    for(it = data.begin();it!=data.end();it++)
    {
        file<<*it<<",";
    }
    file<<label<<"\n";
    file.close();
}

/*
 * train pos and neg samples with label 1 or -1
 */
void DemoImage::train(const char *pospath,int posnum,const char *negpath,int negnum)
{
    Ptr<ml::TrainData> train_data = ml::TrainData::loadFromCSV(pospath,0,-1,-1,String(),',');
    Mat m = train_data->getTrainSamples();
    Ptr<ml::SVM> model = ml::SVM::create();
    model->trainAuto(train_data);
    model->train(train_data);
    model->save("feature.txt");
}

string & DemoImage::trim(string &s)
{
    if(s.empty())
        return s;
    s.erase(0,s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ")+1);
    return s;
}

void DemoImage::split1(string& s, string& delim,vector< string >& ret)
{
    size_t last = 0;
    size_t index=s.find_first_of(delim,last);
    while (index!=std::string::npos)
    {
        ret.push_back(s.substr(last,index-last));
        last=index+1;
        index=s.find_first_of(delim,last);
    }
    //    if (index-last>0)
    //    {
    //        ret.push_back(s.substr(last,index-last));
    //    }
}

void DemoImage::detect(const char *file)
{
    this->LoadImage(file);

    if(this->img->width > 100)
        this->img = resizeImage(this->img);

    int width = this->img->width;
    int height = this->img->height;

    Ptr<ml::SVM> model = Algorithm::load<ml::SVM>("feature.txt");

    float max = -1000;
    int maxi,maxj;
    for(int i=0;i<width-64;i++)
        for(int j=0;j<height-128;j++)
        {
            vector<int> label;
            IplImage *dst = cvCreateImage(cvSize(64,128),img->depth,img->nChannels);
            cvSetImageROI(this->img,cvRect(i,j,64,128));
            cvCopy(this->img,dst);
            vector<float> hog = this->ExtractFeatrure(dst,9,8,16,1,"",false);
            float result = model->predict(hog,cv::noArray(),ml::StatModel::RAW_OUTPUT);
            if(result > max)
            {
                max = result;maxi = i;maxj = j;
            }
        }
    if(max>=1)
    {
        cvResetImageROI(img);
        cvRectangle(img,cvPoint(maxi,maxj),cvPoint(maxi+60,maxj+120),Scalar(0,0,255),1,1,0);
    }
    else
    {
         cvText(img,"None",10,10);
    }
    cvShowImage("detect",img);
    cvWaitKey(5);

}

void DemoImage::detectFromFile(const char *path)
{
    IplImage *img;
    IplImage *grayimg;

    string filename;
    ifstream myfile(path);
    if (myfile)
    {
        while (getline( myfile, filename ))
        {
            detect(filename.c_str());
        }
        myfile.close();
    }
    cvReleaseImage(&img);
}

IplImage * DemoImage::resizeImageScale(IplImage *src,float scale)
{
    CvSize size;
    size.width = src->width*scale;
    size.height = src->height*scale;

    IplImage *dst = cvCreateImage(size,src->depth,src->nChannels);
    cvResize(src,dst,CV_INTER_LINEAR);
    return dst;
}


void DemoImage::cvText(IplImage* img, const char* text, int x, int y)
{
    CvFont font;

    double hscale = 0.5;
    double vscale = 0.5;
    int linewidth = 2;
    cvInitFont(&font,CV_FONT_HERSHEY_SIMPLEX |CV_FONT_ITALIC,hscale,vscale,0,linewidth);

    CvScalar textColor =cvScalar(0,0,255);
    CvPoint textPos =cvPoint(x, y);

    cvPutText(img, text, textPos, &font,textColor);
}
