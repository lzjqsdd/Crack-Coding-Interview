#include <iostream>
#include <cstdio>
using namespace std;


void printV(int (&a)[2])
{
	for(int i=0;i<2;i++)
		cout << a[i] << endl;
}

template<class T,int N>
void printVT(T (&a)[N])
{
	for(T i=0;i<N;i++)
		cout << "T" << a[i] << endl;
}

int main()
{
	int b[2] = {1,2};
	printV(b);
	printVT(b);
	return 0;
}

