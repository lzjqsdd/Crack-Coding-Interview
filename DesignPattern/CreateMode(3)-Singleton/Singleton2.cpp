#include "Singleton2.h"
#include <iostream>
using namespace std;

Singleton2* Singleton2::_instance = new Singleton2();

Singleton2::Singleton2()
{
    cout << "Singleton2..." << endl;
}

Singleton2* Singleton2::instance()
{
    return _instance;
}