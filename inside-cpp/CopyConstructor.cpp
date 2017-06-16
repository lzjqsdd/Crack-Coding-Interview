#include <iostream>
using namespace std;

class BaseString
{
public:
    BaseString(){cout << "Call BaseString Default Constructor" << endl;}
    BaseString(char *str){this->str = str; len = 10;}
    ~BaseString(){}
    BaseString(const BaseString& basestring) //copy constructor
    {
        this->str = basestring.str;
        this->len = basestring.len;
        cout << "Call BaseString Copy Constructor " << endl;
    } 
    char *str;
    int len;
};

class Word
{
public:
    Word(){}
    //Word(char *str){bs.str = str;bs.len = 10;flag = 1;} //默认编译器扩展添加了BaseString的默认构造函数

    
    Word(char *str):
        bs(str)
    {flag = 1;} //basestring调用了用户定义的构造函数

    ~Word(){}

    //没有设定拷贝构造函数
private:
    BaseString bs; //由于包含了member class object,默认的拷贝初始化是递归进行的
    int flag;
};


int main()
{
    char cc[] = "1234";
    Word wd(cc);
    Word wd2 = wd; //测试调用copy constructor
}
