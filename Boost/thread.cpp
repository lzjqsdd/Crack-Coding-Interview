#include <vector>
#include <iostream>
#include <boost/thread/thread.hpp>
using namespace std;
using namespace boost;

void hello()
{
    while(1)
    {
        cout << "hello thread" << endl;
        sleep(5);
    }
}


class A{
public:
    A(int i):i_(i),flag(0){}
    void say(){
            sleep(1);
            cout << "p1: " << *p1 << "," << "p2: " << *p2 << endl;
    }
    void swapp()
    {
        while(1)
        {
            cout << "swap ..." << endl;
            sleep(1);
        }
    }
    int i_;
    boost::shared_ptr<int> p1;
    boost::shared_ptr<int> p2;
    int flag;
};



//读线程
void run1(boost::shared_ptr<int> p)
{
    cout << *p << endl;
}

void run2(boost::shared_ptr<int> p,int i)
{
    while(1)
    {
        *p = i;
        sleep(1);
    }
}

int main()
{
    /*
    boost::shared_ptr<int> p1(new int(10));
    boost::shared_ptr<int> p2(new int(20));

    A a(10);
    a.p1 = p1;
    a.p2 = p2;

    boost::thread t2(bind(&A::swapp,&a));

    vector<boost::thread> v;
    for(int i=0;i<5000;i++)
    {
        //boost::thread t(bind(&A::say,&a));
        v.push_back(boost::thread(boost::bind(&A::say,&a)));
    }
    t2.join();
    for(int i=0;i<5000;i++)
    {
        v[i].join();
    }
    */
    A a(10);
    boost::thread t(boost::bind(&A::swapp,&a));
   // t.join();

    cout << "fadsflkasjflkasjflsadjf" <<endl;


    return 0;
}


