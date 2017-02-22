#include <stdio.h>

static char retarray[20];
char *func(int n)
{
	sprintf(retarray,"%d",n);
	return retarray;
}

char *funcc(int n)
{
	char retarray[20];
	sprintf(retarray,"%d",n);
	return retarray;
//	不能return 局部变量的数组啊！！！会被释放的呀	
}

int main()
{
return 0;
}
