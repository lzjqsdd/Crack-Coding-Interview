//Abstraction.h
#ifndef _ABSTRACTION_H_
#define _ABSTRACTION_H_



class AbstractionImp; //声明

class Abstraction
{
public:
    virtual ~Abstraction();
    virtual void Operation() = 0; //这个operation应该指的是两个维度类之间的关系。比方颜色给形状填充的过程。
protected:
    Abstraction();
private:
};


class RefinedAbstraction:public Abstraction
{
public:
    RefinedAbstraction(AbstractionImp *imp);
    ~RefinedAbstraction();
    void Operation();
protected:
private:
    AbstractionImp *_imp; //
};
#endif