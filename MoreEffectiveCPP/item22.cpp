/*===============================================
# Author: lzjqsdd - lzj7179@163.com
# Last modified: 2017-06-03 23:40
# Filename: item22.cpp
# Description: 考虑用运算符的复制形式(+=,-=,op=)取代其单独形式(+,-,op)
================================================*/

#include <iostream>
using namespace std;
template<class T>
const T operator+(const T& lhs,const T&rhs)
{
    return T(lhs) += rhs;
}

template<class T>
const T operator-(const T& lhs,const T& rhs)
{
    return T(lhs) -= rhs;
}

class A
{
public:
    A(int x):m(x){
        curn = N++;
        cout << "call A ctor..." << curn <<  endl;
    }
    A(const A& a):m(a.m){ //这里参数的const
        curn = N++;
        cout << "call A copy ctor..."<< curn  << endl;
    }

    A& operator+=(const A& rhs)
    {
        m += rhs.m;
        return *this;
    }
    A& operator-=(const A& rhs)
    {
        m -= rhs.m;
        return *this;
    }

    ~A(){cout << "call A dstor..."<< curn << endl;}
    static int N;
private:
    int m;
    int curn;
};

int A::N = 0;


int main()
{
    A a1(10);
    A a2(20);
    A a3 = a1 + a2;
}
