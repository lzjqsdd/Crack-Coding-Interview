#ifndef _PROTOTYPE_H_
#define _PROTOTYPE_H_

class Prototype
{
public:
    virtual ~Prototype();
    virtual Prototype * Clone() const;
    int x;
protected:
    Prototype();
};

class ConcretePrototype:public Prototype
{
public:
    ConcretePrototype();
    ConcretePrototype(const ConcretePrototype& cp); //拷贝构造
    ~ConcretePrototype();
    Prototype *Clone() const;
protected:
private:
};

#endif