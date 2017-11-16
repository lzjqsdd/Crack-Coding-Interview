/*===============================================
# Author: lzjqsdd - lzj7179@163.com
# Last modified: 2017-06-01 10:13
# Filename: item5.cpp
# Description: 谨慎使用类型转换函数
================================================*/
//隐式类型转换
// 关于隐式转换考虑Proxy对象，参见Itm30 Proxy Class
#include <iostream>
using namespace std;
class Rational
{
public:
    Rational(int a):a(a),b(1){}
    Rational(int a,int b):a(a),b(b)
    {}
    operator double() const
    {
        cout << "call implicit convert.."<< endl;
        return a*1.0/b;
    }
    double asDouble() const
    {
        cout << "call implicit convert asDouble"<< endl;
        return a*1.0/b;
    }

    //如果没有重载operator <<,则编译器会寻找一个合适的隐式转换
    /*
    friend ostream & operator<<(ostream&os,const Rational&r)
    {
        os << r.a << "/" << r.b;
        return os;
    }
    */
private:
    int a;
    int b;
};


//另外可能发生隐式转换的地方
template<class T>
class Array
{
public:
    //另外一种解决方式是把参数n用一个新类表示
    explicit Array(int n):
        lb(0),
        hb(n-1)
    {
        data = new T[n];
    }
    Array(int lowBound,int highBound):
        lb(lowBound),
        hb(highBound)
    {
        data  = new T[highBound+1];
    }
    T& operator[](int index)
    {
        return data[index];
    }

private:
    int lb;
    int hb;
    T * data;
};




template<class T>
class Array1
{
public:
    //另外一种解决方式是把参数n用一个新类表示
    //嵌套类
    class ArraySize{
        public:
            ArraySize(int n): _size(n)
            {
            }

            int size() const {return _size;}
        private:
            int _size;
    };
    Array1(ArraySize size):
        lb(0),
        hb(size.size()-1)
    {
        cout << "call Array1 ctor" << endl;
        data = new T[size.size()];
    }
    Array1(int lowBound,int highBound):
        lb(lowBound),
        hb(highBound)
    {
        data  = new T[highBound+1];
    }
    T& operator[](int index)
    {
        return data[index];
    }

private:
    int lb;
    int hb;
    T * data;
};

bool operator==(const Array<int>&lhs,const Array<int>&rhs)
{
    //TODO
    cout << "调用Array1==了"<< endl;
    return false;
}


int main()
{
    Rational r(1,2);
    double d = 0.5*r; //调用operator double()
    cout << d << endl;

    Rational r2 = 5; //调用的是单参数构造函数
    cout << r2 << endl; //如果没有重载<<，那么调用了Rational->double的转换
    //所以避免使用operator double()原始的关键字来做转换运算符
    cout << r2.asDouble() << endl;


    //测试使用模板类
    Array<int>a(10);
    cout << a[2] << endl;
    Array<int>b(10);

    /*
    for(int i=0;i<10;++i)
    {
        //这里如果手贱把a[i]写成了a，那么会调用上述重载的operator==,把b[i]隐式转换为Array<int>了
        //可以在构造函数使用explicit避免隐式调用
        if(a == b[i]) 
            cout << "equal" <<endl;
        else
            cout << "no equal" << endl;
    }
    */


    Array1<int>a1(10);
    Array1<int>b1(10);
    for(int i = 0;i<10;++i)
        if(a1 == b1[i]) //这个时候没法把b1[i]隐式转换为ArraySize，然后再转换为Array<int>
            //这是不被编译器允许的
            cout << "equal " << endl;
        else
            cout << "no equal" << endl;
    
}
