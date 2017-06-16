//main.cpp
//#include "Adapter.h"
#include "Adapter1.h"
#include <iostream>
using namespace std;

int main()
{
    Target *adt = new Adapter(new Adaptee); //直接用上适配器,把Adaptee适配了。
    adt->Request();

    return 0;
}
