/*对sum是否小于0要做判断*/
//http://blog.csdn.net/joylnwang/article/details/6859677
//最大子串和问题
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <climits>
using namespace std;

int find_max1(int a[],int n)
{
	int i,j;
	int maxsum=a[0];
	int sum;
	for(i=0;i<n;i++)
	{
		sum=0;
		for(j=i;j<n;j++)
		{
			sum+=a[j];
			if(sum>maxsum)
				maxsum=sum;
		//	if(sum<0)
		//		sum = 0;
		}
	}
	return maxsum;
}

int find_max(int a[],int n)
{
	int maxsum=a[0];

	for(int i=0;i<n;i++)
		for(int j=i;j<n;j++)
		{
			int sum = 0;
			for(int k=i;k<=j;k++)
				sum+=a[k];

			if(sum>maxsum)
				maxsum=sum;
		}

	return maxsum;
}

int find_max_dp1(int a[],int n)
{
	int maxsum=a[0];
	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=a[i];
		if(sum>maxsum)
			maxsum=sum;
		if(sum<0)
			sum=0;

	}
	return maxsum;
}


int find_max_dp2(int a[],int n)
{
	int maxsum=a[0];

	int sum=0;
	for(int i=0;i<n;i++)
	{
		if(sum>=0)
			sum+=a[i];
		else
			sum=a[i];

		if(sum>maxsum)
			maxsum=sum;

	}

	return maxsum;
}


int main()
{
	int a[5] = {1,4,2,-9,6};
	int b[5] = {-4,-1,-2,-9,-6};

	cout<<"method1:"<<find_max_dp1(b,5)<<endl;
	cout<<"method2:"<<find_max_dp2(b,5)<<endl;
	cout<<"method3:"<<find_max1(b,5)<<endl;
	cout<<"method4:"<<find_max(b,5)<<endl;

	cout<<"method1:"<<find_max_dp1(a,5)<<endl;
	cout<<"method2:"<<find_max_dp2(a,5)<<endl;
	cout<<"method3:"<<find_max1(a,5)<<endl;
	cout<<"method4:"<<find_max(a,5)<<endl;
	return 0;

}
