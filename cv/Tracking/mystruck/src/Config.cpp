#include <Config.h>

Config::Config()
{
	init();
}

void Config::init()
{
	width = 320;
	height = 240;
	basepath = "./train/girl/";
	imgpath = "./train/girl/girl_frames.txt";
	gtpath = "./train/gril/girl_gt.txt";
	budgetSize = 100;
}
