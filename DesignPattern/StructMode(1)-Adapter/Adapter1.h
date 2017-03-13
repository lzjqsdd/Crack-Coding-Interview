#ifndef _ADAPTER_H_
#define _ADAPTER_H_

//对象模式的Adapter实现，适配器继承自客户要求的接口，同时成员包含了第三方类对象。

class Target //客户要求的接口
{
public:
    Target();
    virtual ~Target();
    virtual void Request();
protected:
private:
};

class Adaptee //第三方要适配的类
{
public:
    Adaptee();
    ~Adaptee();
    void SpecificRequest();
protected:
private:
};

class Adapter:public Target //适配器把两个不匹配的类通过多重继承方式连接起来
{
public:
    Adapter(Adaptee* ade);
    ~Adapter();
    void Request();
protected:
private:
    Adaptee* _ade;
};


#endif