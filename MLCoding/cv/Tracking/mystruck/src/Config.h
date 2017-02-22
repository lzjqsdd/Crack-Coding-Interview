#include <iostream>
#include <string>
#include "cv.h"
#include "floatrect.h"
using namespace std;
//读取配置文件

class Config
{
	public:
		Config();
		//~Config();
		int width; //归一化图片的大小
		int height; //高度
		string basepath;
		string imgpath; //训练图片描述文件的位置
		string gtpath; //GroudTruth的位置
		int budgetSize;
		FloatRect m_initbb;//初始BoundBoxing的位置
		void init();
		int searchR;//采样半径
};
