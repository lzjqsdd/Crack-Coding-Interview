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


void printA(A a) //注意这里是传值或者常亮引用才会发生类型转换，如果是引用则不会
{
    cout << "A.m is " << a.m << endl;
}


int main()
{
    printA(10); //这里出现隐式转换
}
