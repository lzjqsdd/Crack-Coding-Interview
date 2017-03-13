#ifndef _SINGLETON2_H_
#define _SINGLETON2_H_

class Singleton2
{
public:
    static Singleton2* instance();
protected:
    Singleton2();
    Singleton2& operator=(const Singleton2&);
    Singleton2(const Singleton2&);
private:
    static Singleton2 * _instance;
};

#endif