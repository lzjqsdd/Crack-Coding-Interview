/*求工资平均数*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
	float salary,sum;

	for(int i=0;i<12;i++)
	{
		cin>>salary;
		sum+=salary;
	}

	printf("$%.2f\n",sum/12.0);
	return 0;
}
