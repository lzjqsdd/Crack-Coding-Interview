/*===============================================
# Author: lzjqsdd - lzj7179@163.com
# Last modified: 2017-06-01 20:40
# Filename: item10.cpp
# Description:  在构造函数中繁殖资源泄露
================================================*/

//如果在构造的过程中异常被抛出，其他已经被被构造的资源怎么处理？
//构造函数内部的异常被传递到外部建立对象的地方

//c++仅仅能删除被完全构造的对象，所以别指望析构函数可以处理已经被构造的资源
//
#include <iostream>
#include <string>
#include <exception>
#include <vector>
using namespace std;
class A
{
//现在试图在构造过程中产生异常，我打算做指针非法访问
//如果p不为null，可以正常构造
public:
    //我这里在构造列表中以nullptr初始化，是为了避免在初始化列表中出问题
    //但是，如果a是一个const类型的指针常亮，只能在列表初始化，这么情况下出现异常
    //怎么处理？没法在列表中捕获异常，列表中支持表达式，把成员初始化任务放到函数中并返回初始化结果
    A(int va,int *p,int c):a(inita(va)),b(initb(p)){
       cout << "call another ctor" << endl;
       *b = c;  //这里随便写的，便于区分另一个构造函数
    }
    A(int va,int *p):a(nullptr),b(nullptr){
        //改造方法是在构造函数中处理异常
        /*
        a = a;
        b = *p;
        */
        a = new int(va); 
        try
        {
            if(p == nullptr)
                throw string("p is null");
            b = new int(*p);
        }
        catch(...)
        {
            cout << "catch Exception " << endl;
            //delete a;
            //delete b;
            cleanup();
            cout << "clear partial member" << endl;
            throw;
        } 

        cout << "call ctor" << endl;
    }
    ~A(){
        cout << "call dstor" << endl;
        //delete a;
        //delete b; //可以发现这里的代码和构造中catch中的重复
        cleanup();
    }
    void print()
    {cout << *a << "," << *b << endl;}

    //把相同代码定义到一起
    void cleanup()
    {
        delete a;
        delete b;
    }

    int* inita(int va)
    { 
        return new int(va);
    }

    int* initb(int *p)
    {
        if(p == nullptr)
        {
            delete a; //因为列表初始化先构造了a
            throw "init b with null pointer";
        }
        return new int(*p);
    }

private:
    int *a;
    int *b;
};


int main()
{
    int a = 10,b = 20;
    A a1(a,&b);
    a1.print();


    /*
    A* a2 = nullptr;
    int n = 10;
    try
    {
        //会发现构造体没完成，没有输出call ctor,a2还是null;
        //但是已经构造的部分资源丢失,无法销毁
        a2 = new A(a,nullptr); //如果构造失败
    }
    catch(...)
    {
        cout << "null error" << endl;
        delete a2; //所以这里的delete null没有卵用
        throw;
    }
    delete a2;
    */


    A* a3 = nullptr;
    try{
        A* a3 = new A(a,nullptr,3);
    }
    catch(...){
        cout << "catch null error " << endl;
        delete a3;
    }
    delete a3;
}
