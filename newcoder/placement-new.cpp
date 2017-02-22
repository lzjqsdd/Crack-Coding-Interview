#include <iostream>
using namespace std;

class Test
{
public:
	Test(int x){_x = x;}
	Test(){_x = 0;}
	~Test(){}

private:
	int _x;
};


#define N 100000000
int main()
{
	int *p = new int[10];
	//Test * tp = new Test[10]; //直接分配会因为没有默认构造函数而分配失败

	//使用placement new来分配内存
	char *buff = new char[sizeof(Test)]; //预先在堆上分配buffer
	//char buff2[sizeof(Test)]; //或者在栈上分配
	
	Test *tp = new(buff) Test(1);


#ifdef TEST_ARRAY
#ifdef PLACEMENT_NEW
	///////////////////////////////////////////////////////////
	//如果要分配一个数组呢？
	char *buff_array = new char[sizeof(Test) * N];
	Test *tpa = (Test*) buff_array;  //强制把内存解释为Test数组
	//for(int i=0;i<N;i++) new(tpa+i)Test(i);
	for(int i=0;i<N;i++) new(tpa+i)Test();
	//delte内存
	for(int i=0;i<N;i++) tpa[i].~Test();
	delete [] buff_array; //这里delete是原始buffer,不能按照tpa来delete

#endif

#ifdef COMMON_NEW
	Test *tpa = new Test[N];
	delete [] tpa;
#endif	
#endif

#ifdef TEST
//测试多次使用相同的buff的效率
#ifdef PLACEMENT_NEW
	char *buff2 = new char[sizeof(Test)];
	for(int i=0;i<N;i++) {Test *tpb = new(buff2)Test();tpb->~Test();}
	delete buff2;
#endif

#ifdef COMMON_NEW
	for(int i=0;i<N;i++) {Test *tpb = new Test;tpb->~Test();delete tpb;}
#endif
#endif
	
}

