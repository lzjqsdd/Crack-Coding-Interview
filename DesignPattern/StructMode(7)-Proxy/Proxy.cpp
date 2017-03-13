#include "Proxy.h"
#include <iostream>
using namespace std;

Proxy::Proxy(Subject* sub)
{
    this->_sub = sub;
}
Proxy::~Proxy(){}
void Proxy::Operation()
{
    cout << "Proxy is Working..." << endl;
    this->_sub->Operation();
}