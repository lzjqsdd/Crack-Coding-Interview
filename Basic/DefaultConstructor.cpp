#include <iostream>
using namespace std;

namespace lzjqsdd
{
	class Foo
	{
	public:
        Foo()
        {
            this->val = 1;
            cout << "Foo Default Constructor" << endl;
        }
        ~Foo(){}
    private:
	    int val;
	};


    class Bar
    {
    public:
        //只有用户定义的构造函数，没有默认构造函数
        Bar(float fval){this->fval = fval;} //测试编译器是否会扩充构造函数来构造foo
        Bar(){this->fval = fval;} //如果增加了默认构造函数，但是有用户代码，编译器是否会扩充
        ~Bar(){}

    private:
        Foo foo; //Foo有默认构造函数
        float fval;
    };
}


using namespace lzjqsdd;
int main()
{
    Bar bb(1);
}
