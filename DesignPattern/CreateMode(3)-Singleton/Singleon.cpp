#include "Singleton.h"

#include <iostream>
using namespace std;

Singleton* Singleton::_instance = NULL; //静态成员初始化在类外部
pthread_mutex_t Singleton::mutex;

Singleton::Singleton()
{
    pthread_mutex_init(&mutex,NULL);
    cout << "Singleton..." << endl;
}

Singleton* Singleton::instance()
{
    if(_instance == NULL)
    {
        pthread_mutex_lock(&mutex);
        if(_instance == NULL)
            _instance = new Singleton();
        pthread_mutex_unlock(&mutex);
    }

    return _instance;
}