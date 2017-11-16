//理解“抛出一个异常”与“传递一个参数”或者“调用一个虚函数”之间的差异
//当调用函数时，程序的控制权最终还会返回到函数的调用处,
//当抛出异常时，程序的控制权永远不会回到抛出异常的地方

//可以这么理解：调用参数自外而内传递，异常是参数自内而外传递

#include<iostream>
using namespace std;


class A
{
public:
    A(int x):m(x)
    {
        cout << "call A ctor " << x << endl;
    }
    A(const A& a) //拷贝构造函数
    {
        cout << "call A copy ctor "<< a.m << endl;
        this->m = a.m;
    }
    ~A(){cout << "call A dstor" << endl;}
    int m;
};


class B:public A
{
public:
    B(int x,int y):A(x),mb(y)
    {
        cout << "call B ctor.." << endl;
    }
    B(const B& b):A(b.m),mb(b.mb)
    {
        cout << "call B copy ctor..." << endl;
    }
    int mb;
};

void f1(A &a)
{
    cout << "start call f1..." << endl;
    cout << a.m << endl;
    a.m--; //对a的改变会影响调用时传递进来的变量。因为调用结束还会回到调用处。
    cout << "end call f1..." << endl;
}

void f2() throw(A&)
{
    cout << "start call f2..." << endl;
    //A a(20);
    //a.m--;

    //测试如果使用子类引用
    B b(10,112);
    A &a = b; //结果并没有调用B的拷贝构造函数,采用的是a的静态类型。
    b.m--;
    throw a; //异常的传递，如果返回局部变量的引用，则该变量因为结束而被析构
    cout << "end call f2 ..." << endl;
}

void f4() throw(A&) //这里抛出的是A，但是实际数据是B类型的
{
    //测试如果使用子类引用
    B b(10,112);
    throw b;//异常的传递，如果返回局部变量的引用，则该变量因为结束而被析构
    cout << "end call f2 ..." << endl;
}

void f5() throw(A&)
{
    try
    {
        f4(); //该函数抛出的异常是B类型的
    }
    catch(A& a)
    {
        throw a; //抛的是A的静态类型的拷贝，此时丢失了B的信息，观察输出多了一次拷贝调用
        //throw; //这个不做拷贝直接把从f4抛出的异常向上抛,
    }
}

void f_test1()
{

    //测试调用
    //A x(20);
    //f1(x);
    //cout << "after f1,x value is " << x.m << endl;

    //测试抛出异常
    //测试结果：在抛出异常后，调用了拷贝构造函数，说明并不是直接返回引用的
    try
    {
        f2();
    }
    catch(A &x){
        cout << "catch exception x is :" << x.m << endl;
        //cout << "catch exception x is :" << x.mb << endl; //提示没有mb成员
    }
}

void f_test2()
{
    try
    {
        f5();
    }
    catch(B &x){ //如果f5中使用的是throw，则该异常被捕获
        cout << "catch B exception x is :" << x.mb << endl; //提示没有mb成员
    }
    //如果是传值捕获则会更多一次拷贝构造
    catch(A &x) //如果f5中使用的是throw a ,则该异常被捕获
    {
        cout << "catch A exception x is:" << x.m << endl;
    }
    //如果异常没有对应的处理程序，则程序terminate

    //上述使用了两次catch，在于函数传递可以发生隐式转换
    //而catch进行异常匹配是：可以进行派生类到父类的的转换，另一个从类型化指针到void*
    //而想int的异常是不会被double捕获的，父类的异常也不会被派生类捕获。
    //而且先应该处理派生类，因为父类很有可能捕获派生类，编译器会发出警告
}

int main()
{
    //f_test1();
    f_test2();
}