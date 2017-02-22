#include <iostream>
using namespace std;

int main()
{
	int a = 1; //a是有符号数
	//如果最高位是1，右移若干位到达i，则最高为到i之间全是1
	cout << a << endl;
	a <<= 31; 
	cout << a << endl;
	a >>= 29;
	cout << a << endl;
}
