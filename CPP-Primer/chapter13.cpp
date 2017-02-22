#include <iostream>
using namespace std;

class Foo
{
public:
  Foo(); //默认构造函数
  Foo(int i);
  //explicit Foo(const Foo&); //拷贝构造函数
  Foo(const Foo&); //拷贝构造函数
  Foo& operator=(const Foo&);
  int gval();
private:
  int val;

};

Foo::Foo()
{
  val = 10;
  cout << "Default Constructed!" << endl;
}

Foo::Foo(int i):
  val(i)
{
  cout << i << endl;
}

//拷贝构造函数
Foo::Foo(const Foo&)
{
  cout << "Copy Constructed!" << endl;
}

//赋值运算符
Foo& Foo::operator=(const Foo& f)
{
  val = f.val+20;
  return *this;
}

int Foo::gval()
{
  return val;
}

int main()
{
  cout << "f1: ";
  Foo f1; //直接初始化
  cout << endl << "f2: ";
  Foo f2(1); //直接初始化
  cout << endl << "f3: ";
  Foo f3 = Foo(); //拷贝初始化,但是被编译器优化了,直接变为了Foo f2();
  cout << endl << "f4: ";
  Foo f4 = f1; //拷贝初始化
  cout << endl << "f5: ";
  Foo f5(f1); //直接初始化,但是根据参数调用了拷贝构造函数
  cout << endl << "f6: ";
  Foo f6 = {1};
  cout << endl << "f7: ";
  Foo f7(); //实际是定义了一个无参数的函数f7,编译器并不会报错
  Foo f8; f8 = f2; //对比下一个
  Foo f9 = f2; //由于重载了=运算符,f9在初始化时加上了20,但是这个时候f9的val并没有初始化值,所以结果是未定义的,而f8默认构造,val为1,再使用赋值运算,值为21
  cout << f2.gval() << endl;
  cout << f8.gval() << endl;


  int i = 32;
  const int &r1 = i*42;//const左值引用绑定到表达式上
  int &&rr2 = i*42 ;//右值引用a

  int &&rr3 = std::move(i);
}
