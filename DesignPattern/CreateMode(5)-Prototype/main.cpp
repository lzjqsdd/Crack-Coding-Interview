#include "Prototype.h"
#include <iostream>
using namespace std;

int main()
{
    Prototype *p1 = new ConcretePrototype();
    Prototype *p2 = p1->Clone();

    cout << p2->x << endl;
    return 0;
}