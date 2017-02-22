#include <Config.h>

Config::Config()
{
	init();
}

Config::init()
{
	width = 320;
	height = 240;
	imgpath = "./train/girl";
	budgetSize = 100;
}

