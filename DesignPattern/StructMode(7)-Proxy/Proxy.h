#ifndef _PROXY_H_
#define _PROXY_H_
#include "Subject.h"

class Subject;

class Proxy:public Subject
{
public:
    Proxy(Subject *sub);
    ~Proxy();
    void Operation();
private:
    Subject *_sub;
};

#endif