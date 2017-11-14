#include <iostream>
using namespace std;

class A
{
public:
    A(int x):m(x){
        cout << "call A ctor" << endl;
    }
    ~A()
    {
        cout << "call A dstor:" << m << endl;
    }
private:
    int m;
};


int func1() throw(int)
{
    A a(1); ///a在stack-unwinding过程中被释放
    cout << "start func1" << endl;
    throw 100;
    cout << "end func2" << endl;
}

int func2() throw(int)
{
    cout << "start func2" << endl;
    A a(2);
    func1();
    cout << "end func2" << endl;
}

int func3()
{
    cout << "call func1" << endl;
    A a(3);
    try{
        func2();
    }
    catch(int i)
    {
        cout << "Caught Exception: " << i << endl;
    }
    cout << "end func3" << endl;
}


int main()
{
    func3();
    return 0;
}
