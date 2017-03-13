#include "Product.h"
#include "AbstractFactory.h"

#include <iostream>
using namespace std;

AbstractFactory::AbstractFactory()
{

}

AbstractFactory::~AbstractFactory()
{

}

ConcreteFactory1::ConcreteFactory1()
{

}

ConcreteFactory1::~ConcreteFactory1()
{

}

AbstractProductA* ConcreteFactory1::CreateProductA()
{
    cout << "CreateProductA By ConcreteFactory1" << endl;
    return new ProductA1(); //这个工厂生产的是A1和B2的产品
}

AbstractProductB* ConcreteFactory1::CreateProductB()
{
    cout << "CreateProductB By ConcreteFactory1" << endl;
    return new ProductB2();
}


ConcreteFactory2::ConcreteFactory2()
{

}

ConcreteFactory2::~ConcreteFactory2()
{

}

AbstractProductA* ConcreteFactory2::CreateProductA()
{
    cout << "CreateProductA By ConcreteFactory2" << endl;
    return new ProductA2(); //这个工厂生产A2和B1的产品
}

AbstractProductB* ConcreteFactory2::CreateProductB()
{
    cout << "CreateProductB By ConcreteFactory2" << endl;
    return new ProductB1();
}
