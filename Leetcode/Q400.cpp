#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

int findNthDigit(int n) {
	int i=1;
	unsigned int s = 9;
	while(n>s*i) //(s-1)*i表示没一段的位数
	{
		n = n-s*i;
		cout<<"step:"<<s*i<<",n:"<<n<<endl;
		s = s*10;
		i++;
	}
	int shang = n/i; //第shange个i位数
	int yushu = n%i; //定位第shang个数的第yushu位
	int x = shang+pow(10,i-1);
	if(yushu == 0)
	{
		x--;
		cout<<x%10<<endl;
		return x%10;
	}
	else
	{
		for(int j=0;j<i-yushu;j++)
		{
			x = x/10;
		}
		int result = x%10;
		cout<< result<<endl;
	}
	return x;
}


int main()
{
	findNthDigit(199);
	findNthDigit(200);
	findNthDigit(201);
	findNthDigit(202);
	return 0;
}
