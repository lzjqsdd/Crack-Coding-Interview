#include <iostream>
using namespace std;
class Base{
public:
	friend Base add(Base &a,Base &b);
	static int count;
	static void show(){cout << count << endl;}
	static void init(){count = 0;}
	Base(){x = 10;cout << "call default constructor" << endl;count++;}
	~Base(){cout << "call default deconstructor" << endl;}
	Base(const Base &base){x = base.x;cout << "call copy constructor " << endl;}
private:
	int x;
};

int Base::count = 0; //为什么加这句话,参考静态成员初始化代码

Base add(Base &a,Base &b)
{
	Base c;
	c.x = a.x + b.x;	
	return c;
}

int main()
{
	Base a,b;
	Base::init();
	Base c = add(a,b);	
	Base::show();
	return 0;
}
