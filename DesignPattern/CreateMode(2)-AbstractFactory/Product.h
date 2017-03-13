#ifndef _PRODUCT_H_
#define _PRODUCT_H_
class AbstractProductA //产品A
{
public:
    virtual ~AbstractProductA();
protected:
    AbstractProductA(); //抽象基类不能实例化
private:
};


class AbstractProductB //产品B
{
public:
    virtual ~AbstractProductB();
protected:
    AbstractProductB();
private:
};


class ProductA1:public AbstractProductA
{
public:
    ProductA1();
    ~ProductA1();
protected:
private:
};

class ProductA2:public AbstractProductA
{
public:
    ProductA2();
    ~ProductA2();
protected:
private:
};

class ProductB1:public AbstractProductB
{
public:
    ProductB1();
    ~ProductB1();
protected:
private:
};

class ProductB2:public AbstractProductB
{
public:
    ProductB2();
    ~ProductB2();
protected:
private:
};

#endif