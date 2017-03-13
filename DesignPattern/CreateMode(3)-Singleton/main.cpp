#include "Singleton.h"
#include "Singleton2.h"
#include <iostream>

using namespace std;

int main()
{
    Singleton *s1 = Singleton::instance();
    Singleton *s2 = Singleton::instance(); //实例只会被创建一次

    if(s1 == s2) cout << "s1 == s2" << endl;

    Singleton2 *s3 = Singleton2::instance();
    Singleton2 *s4 = Singleton2::instance();

    if(s3 == s4) cout << "s3 == s3" << endl;

    //运行会发现Singleton2先输出，因为其在定义时就创建了对象。
    return 0;
}