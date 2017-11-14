/*===============================================
# Author: lzjqsdd - lzj7179@163.com
# Last modified: 2017-06-01 11:07
# Filename: item8.cpp
# Description:  理解各种不同含义的new和delete
# Reference: https://kelvinh.github.io/blog/2014/04/19/research-on-operator-new-and-delete/
================================================*/

//operator new(size_t)
//operator new(size_t,void *p); //这就是placement new ，多了一个参数指定空间

#include <iostream>
#include <memory>
using namespace std;
class A
{
public:
    A(){cout <<"call ctor" << endl;m = 0;}
    ~A(){cout << "call dstor" << endl;}
    //返回void是返回了一个未经处理的指针，未初始化的内存
    //operator new的职责只分配内存，对构造函数一无所知
    //而在分配的内存上构造对象，则是无所不能的编译器做了
    void* operator new(size_t size,void *p,const string &str) //后面参数可以自己跟,但是size必须放第一个
    {
        cout << "self define operator  new" << endl;
        cout << str << endl;
        if(!p){
            cout << "null address" << endl;
            return ::operator new(size); //如果没有制定空间则需要分配,::表示使用全局的operator new
        }
        return p;
    }

    void operator delete(void *p){
        cout << "self define operator delete" << endl;
        if(!p) //在调用前判断p指向内存是否已经被析构，加上判断避免crash
            ::operator delete(p);
    }


    //重载operator new[]
    void* operator new[](size_t size)
    {
        cout << "call operator new []" << endl;
        return ::operator new[](size);
    }
    //重载operator delte[]
    void operator delete[](void *p)
    {
        cout << "call operator delete[]" << endl;
        if(!p)
            ::operator delete[](p);
    }

    void printA()
    {
        cout << "A value is : "<< m << endl;
    }

    void set(int val) {m = val;}
private:
    int m;
};


int main()
{
    //此处使用的new是new操作符，首先进行内存分配，然后调用构造函数
    A * a = new (nullptr,"test operator new")A;
    a->printA();
    //delete时，如果重载函数中调用了operator delete，会crash
    //因为在调用这句话,a先被析构了,内存已经被销毁，此时再尝试delete一个null出错
    delete a; //如果去掉这句话会发现输出没有调用析构

    //调用delete发生类似代码
    //a->~A();  先析构
    //operator delete(a); 然后释放内存

    //测试placement new
    //char buf[sizeof(A)];
    //A *a2 = new (buf,"test buf")A;
    //delete a2; //为什么这段话因为自定义中delete而导致程序崩溃呢？

    //测试全局的operator new
    //A * b = static_cast<A*>(::operator new(sizeof(A)));
    //delete b;
    
    //测试数据的分配
    A *arr = new A[3];
    arr[0].set(1);
    arr[1].set(2);
    arr[2].set(3);
    arr[0].printA();
    delete [] arr;
}


//总结：
//(1)如果程序频繁创建销毁对象，则可以通过提前分配一个buffer，然后在固定空间上进行对象创建,避免频繁申请内存带来的性能下降
//(2)operator new 和 operator delete是一对，如果只做内存处理，不涉及对象创建，则可以直接调用这两个
//类似于malloc 和free
//(3)如果需要对象创建，则调用new / delete，或者placement new 形式的new (buff) 
