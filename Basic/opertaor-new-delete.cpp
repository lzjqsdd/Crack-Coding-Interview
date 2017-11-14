#include <iostream>
#include <string>
using namespace std;

class TestNew
{
public:
	TestNew(){cout << "constructor of X" << endl;}
	~TestNew(){cout << "deconstructor of X" << endl;}

	void * operator new (size_t size,string str)
	{
		cout << "operator new size " << size << "with string " << str << endl;
		return ::operator new(size);
	}

	void * operator new (size_t size)
	{
		cout << "operator new size " << size << endl;
		return ::operator new(size);
	}

	void operator delete(void * pointee)
	{
		cout << "operator delete" << endl;
		::operator delete(pointee);
	}

private:
	int num;
};


int main()
{
	//TestNew *px = new("A new class") TestNew; //new 调用了被重载的operator new 操作符
	TestNew *px = new TestNew; //new 调用了被重载的operator new 操作符
	delete px;

	return 0;
}
