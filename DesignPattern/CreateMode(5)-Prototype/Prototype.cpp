#include "Prototype.h"
#include <iostream>
using namespace std;

Prototype::Prototype()
{}

Prototype::~Prototype()
{}

Prototype* Prototype::Clone() const
{
    return NULL;
}

ConcretePrototype::ConcretePrototype()
{
    x = 2;
}

ConcretePrototype::ConcretePrototype(const ConcretePrototype &cp)
{
    cout << "ConcretePrototype copy..." << endl;
    x = cp.x; //可以使用默认的memberwise方式实现拷贝构造。
}

ConcretePrototype::~ConcretePrototype()
{

}

Prototype* ConcretePrototype::Clone() const
{
    return new ConcretePrototype(*this);
}