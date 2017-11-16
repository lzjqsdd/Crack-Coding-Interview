/*===============================================
# Author: lzjqsdd - lzj7179@163.com
# Last modified: 2017-06-01 16:02
# Filename: item9.cpp
# Description:  使用析构函数防止资源泄露
# Reference: https://vimsky.com/article/1690.html
================================================*/

//写在前面：
//异常安全(exception-safe)是指在程序出现异常的情况下还可以继续运行
//出现异常的语句之后的代码不会被执行，如果之后的代码涉及到内存释放，则会发生memory leak
//c++ 提供了异常捕捉机制。try{} cathc(...){}
//catch中有一份内存清楚代码，之外也有一份。一个正常处理，一个在异常情况下处理
//烦人的指针可以通过智能指针来处理
//
//或者写一个资源handle类，在构造或者析构时负责资源管理。但是该handle类应该可以隐式转换到原有的资源类
#include <iostream>
#include <stdexcept>
using namespace std;
class A
{
public:
    A():m(0){}
    void process(int x)
    {
        if(x == 0)
            throw x;
        cout << "value is " << 10.0 / x << endl; //这个处理过程可以会出错,除0错误
    }

    A(const A& x) ///赋值构造函数
    {
        this->m = x.m;
    }
private:
    int m;
};


class AHandler
{

public:
    AHandler(A *a):a(a){}
    ~AHandler(){}
    operator A*() {return a;} ///实现AHandler到A的隐式转换
private:
    A *a;
};


int main()
{
    //测试try..catch
   int n = 10; 
   while(n>=0)
   {
       A *pa = new A();
       try{
           pa->process(n); //可能出错
       }
       //catch完之后怎么不调用catch里面的呢
       catch(...) //...表示捕获所有异常
       //catch(const std::exception &e)
       {
           cout << "divide 0 error" << endl; //为什么没有输出呢？
           //cout << "divide 0 error " << e.what() << endl;
           delete pa;
           throw;
       }
       delete pa;
       n--;
   }

   //测试AHandle
   //即使出错，ah也会被析构回收

   /*
   int x = 10;
   while(x >=0)
   {
       AHandler ah(new A);
       static_cast<A*>(ah)->process(x); //这个例子不太合适
       x--;
   }
   cout << "here" << endl;
   */

   return 0;
}

//总结：
//(1)资源应该被封装到一个对象里,通常能避免存在异常环境里发生资源泄露
