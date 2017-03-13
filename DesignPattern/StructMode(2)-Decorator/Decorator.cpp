#include "Decorator.h"
#include <iostream>
using namespace std;

Component::Component()
{
}

Component::~Component()
{
}

void Component::Operation()
{
    
}

ConcreteComponent::ConcreteComponent()
{}

ConcreteComponent::~ConcreteComponent()
{}

void ConcreteComponent::Operation()
{
    cout << "ConcreteComponent Operation" << endl;
}

Decorator::Decorator(Component *com)
{
    this->_com = com;
}

Decorator::~Decorator()
{
}

void Decorator::Operation()
{
}

ConcreteDecorator::ConcreteDecorator(Component *com):
    Decorator(com)
{
}

ConcreteDecorator::~ConcreteDecorator()
{
    delete _com;
}

void ConcreteDecorator::Operation()
{
    _com->Operation();
    this->Addedbehavior(); //好吧，在这里加装饰了。挂上帘子了
}

void ConcreteDecorator::Addedbehavior()
{
    std::cout<<"ConcreteDecorator::AddedBehacior...."<<std::endl;
}