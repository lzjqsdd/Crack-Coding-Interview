//谨慎使用异常规格(exception specifications)

//这句话什么意思呢？在item10~12中的测试程序其实已经被这个问题困扰了
//定义了如下函数,对每个函数指定了确定的类型参数规格
//所以如果无法捕获对应的异常，缺省行为是调用terminate,而terminate调用abort
//导致程序直接终止，并且异常触发的栈中的其他变量没有被释放。
#include <iostream>
#include <exception>
using namespace std;

class UnexpectedException{};
void convertUnexpected()
{
    cout << "call own exception..." << endl;
    throw UnexpectedException();
}

void f1() throw(double)
{
    throw 10.0;
}

void f2() throw(int)
{
    try
    {
        f1();
    }
    catch(int x)
    {
        cout << "x" << endl;
    }
}

void f3() throw(UnexpectedException)
{
    throw 'x'; //not in exceptino-specification
    //不匹配，但是把unexpected转换成了UnexpectedException自定义的
}

void f4() throw(int)
{
    set_unexpected(convertUnexpected); //注释掉就会terminate了
    try
    {
        f3();
    }
    catch(UnexpectedException e)
    {
        cout << "catch unexpectedException ..." << endl;
    }
    catch(...)
    {
        cout << "x" << endl;
    }
}

int main()
{
    //f2();
    //输出：terminate called after throwing an instance of 'double'
    f4();
}

//总结：理解不够透彻
//exception-specification要谨慎使用