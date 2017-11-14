#include <iostream>
#include <cstdio>
using namespace std;

class Base
{
public:
	Base(){};
	virtual void display(){cout << "Base" << endl;}
	void display2(){cout << "Base2" << endl;}
};

class Derive:public Base
{
public:
	Derive(){};
	virtual void display(){cout << "Derive" << endl;}
	void display2(){cout << "Derive2" << endl;}
};

class C:public Derive{
public:
	C(){};
	void display(){cout << "C" << endl;}
};

int main()
{
	/*
	Derive dd;
	Base &b = dd;
	b.display();
	Derive dd2;
	Base &b2 = dd2;
	b2.display2();	
	dd2.display2();
	*/
	C c;
	Base &d = c;
	d.display();

	return 0;
}
