#ifndef _PRODUCT_H_
#define _PRODUCT_H_

class Product
{
public:
    virtual ~Product() = 0;
protected:
    Product(); //屏蔽构造函数
private:

};

class ConcreteProduct: public Product
{
public:
    ~ConcreteProduct();
    ConcreteProduct();
protected:
private:
};

#endif