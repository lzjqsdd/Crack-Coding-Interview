//Foo.h
#ifndef __FOO__
#define __FOO__

class Foo{
  private:
  	int x;
  public:
	Foo();
  	void setX(int x); //没有const，意味着不安全
  	int getX() const; //有const意味着该函数不会修改Foo的成员。
};

#endif
