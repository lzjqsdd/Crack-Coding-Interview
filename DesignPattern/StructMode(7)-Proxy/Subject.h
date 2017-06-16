#ifndef _SUBJECT_H_
#define _SUBJECT_H_

class Subject
{
public:
    virtual ~Subject();
    virtual void Operation();
protected:
    Subject();
};

class ConcreteSubject:public Subject
{
public:
    ConcreteSubject();
    ~ConcreteSubject();
    void Operation();
};

#endif