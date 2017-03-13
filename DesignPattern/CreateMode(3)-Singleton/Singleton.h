#ifndef _SINGLETON_H_
#define _SINGLETON_H_
#include <pthread.h>
class Singleton
{
public:
    static Singleton* instance();
protected:
    Singleton();
    Singleton(const Singleton&); //将拷贝构造和=操作符也保护起来，防止被复制
    Singleton& operator=(const Singleton&);
private:
    static Singleton* _instance;
    static pthread_mutex_t mutex; //线程互斥锁
};

#endif