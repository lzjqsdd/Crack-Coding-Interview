/*===============================================
# Author: lzjqsdd - lzj7179@163.com
# Last modified:	2017-06-02 09:41
# Filename:		item11.cpp
# Description:  禁止异常信息(exception)传递到析构函数外
================================================*/

//两种情况下调用析构函数
//(1) 对象正常结束或者显式调用delete
//(2) 异常处理系统删除一个对象
//
//
//如果异常在析构函数中抛出，没有被Session的析构函数捕获
//catch(...)可以捕获所有异常，如果不向外层throw,则这些异常被忽略
#include <iostream>
using namespace std;
class A
{
public:
    A(int *p):m(nullptr)
    {
        m = p;
    }
    ~A()
    {
        try
        {
            //假设可能有异常出现
            if(m == nullptr)
                throw "nullptr error";
            cout << "stack unwinding" << endl;
            int a = *m;
        }
        catch(...){
            cout << "catch exception..." << endl; //这句话为了测试，因为这句话也可能有异常，最好的办法是catch中什么都没有
            delete m;
            //throw; //测试：如果向析构函数外抛出异常，则会被terminate,程序直接终止
        }
        cout << "析构函数内部处理了异常" << endl; //注释掉上述的throw可以执行到这里.
        delete m;
    }
private:
        int *m;
};


int main()
{
    int x = 10;
    //A a(&x);
    A a(nullptr);
}


//总结：避免异常在析构函数内部抛出
//如果因为try发生异常在stack-unwinding过程中调用了析构函数释放资源，结果析构中也出现并抛出了异常
//则会导致调用terminate函数，直接终止程序，导致资源无法释放,出现内存泄露
//通过捕获并忽略异常保证够在异常转递的stack-unwinding过程中，防止 terminate 被调用，保证资源能够正常释放
//
//stack-unwinding通常和异常处理相关，指的是scope结束，编译器依次销毁scope中的资源
//Reference:https://stackoverflow.com/questions/2331316/what-is-stack-unwinding
//参考代码:stack-unwinding.cpp
