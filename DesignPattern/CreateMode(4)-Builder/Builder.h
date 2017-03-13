#ifndef _BUILDER_H_
#define _BUILDER_H_
#include <string>
using namespace std;

class Product;

class Builder //统一建筑步骤接口
{
public:
    virtual ~Builder();
    virtual void BuilderPartA(const string &buildPara) = 0;
    virtual void BuilderPartB(const string &buildPara) = 0;
    virtual void BuilderPartC(const string &buildPara) = 0;
    virtual void BuilderPartD(const string &buildPara) = 0;
    
    virtual Product* GetProduct() = 0;
protected:
    Builder();
private:
};

class ConcreteBuilder:public Builder //可以有不同的工人（或者建筑队）
{
public:
    ConcreteBuilder();
    ~ConcreteBuilder();
    void BuilderPartA(const string &buildPara); //每层可以有不同的设计风格，用参数来控制
    void BuilderPartB(const string &buildPara);
    void BuilderPartC(const string &buildPara);
    void BuilderPartD(const string &buildPara);

    Product* GetProduct();
protected:
private:
};

#endif