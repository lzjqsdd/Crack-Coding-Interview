//四种cast类型

#include <iostream>
using namespace std;
class Base
{
public:
	Base(){}
	virtual void func(){}
	int a;
};

class Child:public Base
{
public:
	Child(){}
	int b;
};


typedef void (*FuncPtr)(); //无返回值类型

int doSomething()  //有返回值的一个函数
{
	cout << "doSomething..."<<endl;
	return 0;
}

int main()
{
	Child * pc = new Child();
	Base &pb = *pc;
	Base * pd = dynamic_cast<Child*>(&pb);	 //继承关系必须满足多态(有虚函数）



	//reinterpter_cast在函数指针之间的转换
	FuncPtr funcPtrArray[10];

	//想把doSomething放到funcPtrArray中
	funcPtrArray[0] = reinterpret_cast<FuncPtr>(&doSomething);
	funcPtrArray[0]();
	return 0;
}
