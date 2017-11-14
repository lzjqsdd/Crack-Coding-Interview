#include <iostream>
using namespace std;

int main()
{
	int a[4] = {1,2,3,4};
	cout << a << endl;
	cout << &a[0] << endl;
	cout << &a[1] << endl;
	cout << &a[2] << endl;
	cout << &a[3] << endl;
	cout << &a << endl;
	cout << &a+1 << endl;
	cout << &a+2 << endl;
}
