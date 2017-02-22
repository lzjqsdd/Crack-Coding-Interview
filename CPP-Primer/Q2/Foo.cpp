//Foo.cpp
#include "Foo.h"
Foo::Foo()
{
  x = 10;
}

void Foo::setX(int x)
{
	this->x = x;
}

int Foo::getX() const
{
	return x;
}
