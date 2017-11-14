#include <iostream>
#include <vector>
#include <boost/shared_ptr.hpp>

using namespace std;


class B{
    public:
        B(int x):a(x){std::cout << "call b ctor..." << a << std::endl;}
        ~B() {std::cout << "call b dstor..." << a << std::endl;}
    private:
        int a;
};

class A
{
typedef shared_ptr<B> pint;
public:
    A(){
        data[0].reset(new B(0));
        data[1].reset(new B(1));
    }
    pint data[2];
};


int main()
{
    A a;
}
