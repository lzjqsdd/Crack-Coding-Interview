#ifndef _ADAPTER_H_
#define _ADAPTER_H_

//类模式的Adapter实现，在类层面实现了适配器

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

class Adapter:public Target,private Adaptee //适配器把两个不匹配的类通过多重继承方式连接起来
{
public:
    Adapter();
    ~Adapter();
    void Request();
protected:
private:
};


#endif