/*===============================================
# Author: lzjqsdd - lzj7179@163.com
# Last modified: 2017-06-02 23:29
# Filename: item19.cpp
# Description: 理解临时对象的来源
================================================*/

#include <iostream>
using namespace std;

void swap(int a,int b)
{
    int tmp = a; //这里的tmp不是临时变量，而是局部对象
    a = b;
    b = tmp;
}


//c++中真正的临时对象是看不见的
//建立未命名的非堆对象会产生零食对象：
//(1)函数参数的隐式类型转换
//(2)函数返回对象

class A
{
public:
    A(int x):m(x){
        cout << "call A ctor ..." << endl;
    }
    ~A(){
        cout << "call A dstor ..." << endl;
    }
    int m;
};


//如果参数是非常量引用，如果发生拷贝，函数修改的是这个临时变量的值，这不是程序员所期望的
void printA(A a) //注意这里是传值或者常量引用才会发生类型转换，如果是引用则不会
{
    cout << "A.m is " << a.m << endl;
}

A printB()
{
    cout << "Test return value..." << endl;
    //A a(20);
    //return a;  //关于返回值优化
    return A(20);
}

int main()
{
    //printA(10); //这里传递参数时出现隐式转换 
    A a = printB();
    cout << "here "  << endl; //输出的dstor是在这句之后
}

