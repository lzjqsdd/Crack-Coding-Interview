#include "Foo.h"

int main()
{
	//const Foo fo;
	//fo.setX(10); //const对象调用非const成员函数，报错。

	const Foo fo;
	fo.getX();
}
