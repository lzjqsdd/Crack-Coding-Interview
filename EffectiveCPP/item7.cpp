/*===============================================
# Author: lzjqsdd - lzj7179@163.com
# Last modified: 2017-06-01 10:15
# Filename: item7.cpp
# Description: 不要重载 operator&&()  operator||() operator,() 三种符号
# Reference: http://www.java2s.com/Tutorial/Cpp/0200__Operator-Overloading/OverloadingtheCommaOperator.htm
================================================*/

//bool短路求值法，即使有部分表达式未测试，bool表达式也会停止运算
//对于成员函数operator && : expr1 && expr2 等价于 expr1.operator&&(expr2)
//对于Global函数operator&& : expr1 && expr2 等价于 operator&&(expr1,expr2)
#include <iostream>
#include <vector>
using namespace std;


//函数调用时要运算其所有参数，和短路求值是不同的（短路求值部分表达式是可以不运算的)
//所以重载了&&，operator&&是不满足短路求值的。
//
class A{
public:
    A(){b = false;}
    bool operator&&(const A& a)
    {
        return a.b && this->b;
    }
    A& set(bool flag)
    {
        if(flag)
            cout << "call true" << endl;
        else
            cout << "set false" << endl;
        b = flag;
        return *this;
    }

    //测试重载逗号表达式
    A operator,(const A &op2)
    {
        cout << "call operator,() func "<< endl;
        A tmp;
        tmp.b = op2.b;
        return tmp; //返回的是第二个表达式的值
    }

    bool b;
};


int main()
{
    A a1,a2;

    //按照bool短路求值，第一个失败是不调用第二个的
    //但是实际计算了第二个表达式了
    bool flag = a1 && a2.set(true);


    //测试内建的逗号表达式
    int a = 0;
    vector<int> v= {1,2,3,4};
    auto it = v.begin();
    auto x = (a++,++it); //这里必须加括号，不然编译器会解释成(x = a++),(++it)
    //如果使用int a = (a++,++it)会提示无法完成Iterator到int的转换
    cout << *x << endl;


    ///测试重载的逗号表达式
    A t1,t2,t3;
    A t4 = (t1,t2.set(true),t3.set(false));
    if(t4.b) cout << "true" << endl;
    else cout << "false" << endl;
    //如果服从内建类型的规则，从左往右计算表达式，但是因为operator,是函数形式，其参数的计算顺序不确定
    //在g++编译器测试下,先计算了最后一个表达式，然后计算的中间的
    return 0;
}


//所以：无论何时都不要重载逗号表达式,目前接触到重载逗号表达式的在boost中出现过
//https://stackoverflow.com/questions/5602112/when-to-overload-the-comma-operator
//可以重载的有:
//(1)四则运算符及其++,--,+=,-=，*=,/=,各类位运算符
//(2)访问操作符[],->,
//(3)operator new ,operator delete
//(4)调用符号();
