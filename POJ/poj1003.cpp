/*浮点数加和求平均*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
	float c;
	while(~scanf("%f",&c) && c!=0.00)
	{
		float sum = 0;
		int i;
		for(i=1;;i++)
		{
			sum+=1.0/(i+1);
			if(sum > c)
				break;
		}
		cout<<i<<" card(s)"<<endl;

	}
}
