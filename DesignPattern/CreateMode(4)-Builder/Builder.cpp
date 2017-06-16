#include "Builder.h"
#include "Product.h"

#include <iostream>
using namespace std;

Builder::Builder()
{}
Builder::~Builder()
{}

ConcreteBuilder::ConcreteBuilder()
{

}

ConcreteBuilder::~ConcreteBuilder()
{

}

void ConcreteBuilder::BuilderPartA(const string& buildPara)
{
    cout << "Step1: Build ParaA... " << buildPara << endl;
}
void ConcreteBuilder::BuilderPartB(const string& buildPara)
{
    cout << "Step2: Build ParaB... " << buildPara << endl;
}
void ConcreteBuilder::BuilderPartC(const string& buildPara)
{
    cout << "Step3: Build ParaC... " << buildPara << endl;
}
void ConcreteBuilder::BuilderPartD(const string& buildPara)
{
    cout << "Step4: Build ParaD... " << buildPara << endl;
}

Product* ConcreteBuilder::GetProduct()
{
    BuilderPartA("pre-defined"); //默认参数
    BuilderPartB("pre-defined");
    BuilderPartC("pre-defined");
    BuilderPartD("pre-defined");

    return new Product();
}