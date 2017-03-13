//Decorator.h
#ifndef _DECORATOR_H_
#define _DECORATOR_H_


//Component这个虚基类什么作用呢？
//我们考虑下不管什么房子，基本都会有窗口，都有挂窗帘的地方。
//也就是说从一开始最基本的房子就具备了挂窗帘的能力。房子A,B,C...都可以挂帘子
//如果我们的Decorator类只能装饰房子A,那对于B,C...之类的房子我们岂不是还得分别
//定义这些装饰的类。

//这里想到了UI组件的设计。灵活的组合，其实这种组合能力其实在Base类中已经做好了准备
//只不过各个Concrete类分别有自己的样式，比如Button,Textview,Webview之类的。然而都可以加滚动条。

class Component
{
public:
    virtual ~Component();
    virtual void Operation();
protected:
    Component();
private:
};


class ConcreteComponent:public Component
{
public:
    ConcreteComponent();
    ~ConcreteComponent();
    void Operation();
};

class Decorator:public Component //这个Decorator也是基类，其他子类都可以用来装饰Component
{
public:
    Decorator(Component *com);
    virtual ~Decorator();
    void Operation();
protected:
    Component * _com;
private:
};


class ConcreteDecorator:public Decorator
{
public:
    ConcreteDecorator(Component *com);
    ~ConcreteDecorator();
    void Operation();
    void Addedbehavior();
};

#endif