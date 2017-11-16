//---------------------------------------------------
//|自增自减操作符前缀形式和后缀形式的区别 by lzjqsdd|
//---------------------------------------------------
//不论是++还是--，其前缀形式都只有一个参数，无法区分，所以c++规定了后缀形式有一个int类型的参数，传递0进去
//而前缀形式没有
//以下代码仅提供++的测试，--类似
#include <iostream>
using namespace std;
class A
{
public:
    A():a(0){}
    //++前缀，++A,返回A&是为了可以实现++(++A),返回一个左值的引用
    A& operator++() {
        cout << "call ++A" << endl;
        ++a;return *this;
    }
    //++后缀,首先返回的是原始的值，然后A再自增，这时候放回的是const
    //如果是const引用，会出现外部引用了局部变量的问题
    //如果返回引用会是的A++++成立，而内建类型是不允许的
    //而且(A++)++之后A只自增了一次，第二次是在返回的对象上自增的。与感官上不符合
    const A operator++(int){
        cout << "call A++" << endl;
        A old = *this; ++this->a; return old; //而建立临时对象多了临时对象的构造和析构
        //所以在自定义类型是最好多使用前缀++
        //参考item19:建立一个临时对象作为返回值
    }
    void printA(){cout << "value is " << a << endl;}
private:
    int a;
};


int main()
{
    A ta;
    ta++; //ta = 1

    A b = ta++; //ta = 2;
    b.printA(); //b = 1;

    ta.printA();
    ++ta; //ta = 3
    ta.printA();
    //(ta++)++; ++(ta++); // 这两种形式都不会编译通过，试图修改const的对象
    (++ta)++;  //ta = 5
    ta.printA();
    ++(++(++ta));
    ta.printA();

    ta.operator++(0);
    ta.operator++();
}

