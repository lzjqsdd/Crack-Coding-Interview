#include "Subject.h"
#include "Proxy.h"
#include <iostream>
using namespace std;

int main()
{
    Subject *ss = new ConcreteSubject();
    Proxy *proxy = new Proxy(ss);
    proxy->Operation(); //用代理来处理
    return 0;
}