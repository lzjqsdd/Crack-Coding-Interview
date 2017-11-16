//避免无用的确实参数构造
//
#include <iostream>
#include <memory>
using namespace std;
class A
{
public:
    A(int x){a = x;}
    int a;
};

typedef A* PA;

int main()
{
    //method1
    //A array[10]; //对于有参数构造方式，非堆上构造的方式无法分配内存。
    A array[] = {A(1),A(2),A(3)}; //使用列表初始化，调用有参构造

    //method2
    PA parray[10]; //声明一个指针数组(指针类型属于内建类型，内存大小是确定的），但是如果是对象数组
    //在不调构造函数无法分配具体空间

    //method3
    PA * pp =  new PA[10]; ///此时分配的都是指针类型的大小，也可以通过
    //但是pp中的指针并没有指向
    //使用for循环复制pp元素,自己要负责堆上内存的销毁。另外通过指针数组的方式增加了内存量。
    //既要维护指针的大小也要维护对象空间的大小
    for(int i=0;i<10;++i)
        pp[i] = new A(i);


    //method4
    A a[10](2);//这种方式也可以唉
    cout << a[0].a << endl;

    //method5
    //使用placenment new 
    //方法：new(内存)type
    void *rawMemory = operator new[](10*sizeof(A)); ///提前分配内存
    A *ppa = static_cast<A*>(rawMemory);
    for(int i = 0;i<10;++i)
        new (&ppa[i])A(i); //但是仍然要提供构造参数
    operator delete[](rawMemory);//删除数组的方式
    //而delte[]ppa是未定义的,毕竟ppa内存不是new操作符分配的
}
