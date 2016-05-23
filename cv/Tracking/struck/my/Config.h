#include <iostream>
#include <string>
using namespace std;
//读取配置文件

class Config
{
	public:
		Config();
		~Config();
		int width; //归一化图片的大小
		int height; //高度
		string imgpath;
		string resultpath;
		int budgetSize;
		Rect m_initbb;//
		init();
}
