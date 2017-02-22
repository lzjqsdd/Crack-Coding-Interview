/*
result = CRW*Vs/sqrt(1+(crw)^2)
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

#include <iomanip>
using namespace std;

int main()
{
	double vs,r,c,w;
	int num;
	cin>>vs>>r>>c>>num;
	while(num--)
	{
		cin>>w;
		double re = c*r*w;
		cout<<setprecision(3)<<fixed<<(re*vs)/sqrt(1+re*re)<<endl;
	}

	return 0;
	
}
