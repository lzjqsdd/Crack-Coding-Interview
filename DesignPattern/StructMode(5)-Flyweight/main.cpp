//main.cpp
#include "Flyweight.h"
#include "FlyweightFactory.h"
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    FlyweightFactory *fc = new FlyweightFactory();
    Flyweight *fw1 = fc->GetFlyweight("hello");
    fw1->Operation("testtest");
    Flyweight *fw2 = fc->GetFlyweight("world!");
    Flyweight *fw3 = fc->GetFlyweight("hello");
    fw3->Operation("testtest2");
    return 0;
}