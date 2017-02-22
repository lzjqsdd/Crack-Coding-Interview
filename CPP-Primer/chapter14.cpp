#include <iostream>
using namespace std;

struct absInt {
  int operator()(int val) const {
    return val < 0 ? -val:val;
  }
}

  int main()
  {
    absInt ai;
    ai(10); //a是个对象，但是可以像函数一样使用
  }
