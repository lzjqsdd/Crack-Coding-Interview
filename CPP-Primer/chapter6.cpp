#include <iostream>
using namespace std;

void foo(const int i)
{
  cout << "i:" << endl;
}

void foo_array(int *a)
{
  cout << a[0] << endl;
}

void lookup(int *p)
{
  *p = 20;
  cout << "no-const func" << *p << endl;
}

void lookup(const int *p)
{
  cout << "const func"  << *p << endl;
}

int global_a = 101;
int global_b = 201;
void defaultArg(int a = global_a,int b = global_b)
{
  cout << "gloabl_a:" << a <<endl << "global_b:" << b << endl;
}

int main()
{
  /*
  int i1 = 10;
  foo(i1);
  const int i2 = 12;
  foo(i2);
  */

  /*
  int ai0 = 10;
  foo_array(&ai0); 
  int b[3] = {1,2,3};
  foo_array(b);
  */

  /*
  int i = 1024;
  int *p = &i;
  int * const p2 = &i;
  const int *p3 = &i; //分别观察不同的重载函数的调用情况，编译器对于非常量的参数选择非常量的版本。均指底层const
  lookup(p);
  lookup(p2);
  lookup(p3);
  */

  int global_a = 234;
  global_b = 235;
  defaultArg(); //这里gloabl_a使用的依然是全局的默认值,和局部变量值无关。
}

