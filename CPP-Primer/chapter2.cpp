/*
 *This chapter is about pointer,const,typedef,auto,declval,constexpr
 */

#include <iostream>
using namespace std;

int i7 = 10;
const int j7 = 12;
constexpr int p_i7 = 43;

int main()
{

    /* About pointer */
    //  int i = 42;
    //  int *pi = 0;
    //  int *pi2 = &i;
    //  int *pi3;

    //  pi3 = pi2;
    //  pi2 = 0;

    //指向指针的指针
    int ival = 1024;
    int *pi = &ival;
    int **ppi = &pi;

    //cout << "ival: " << ival << endl
    // << "pi: " << pi << endl
    // << "*pi: " << *pi << endl
    // << "ppi: " << ppi << endl
    // << "*ppi: " << *ppi << endl
    // << "**pi: " << **ppi << endl;

    //指向指针的引用
    int *&r = pi; //r是对指针p的引用,离变量名最近的符号对变量类型有最直接的影响，*说明r引用的是一个指针
    cout << "pi: " << pi << endl;
    cout << "r: " << r << endl; //也就是说r引用了指针p，和p的存储位置是一样的。

    r = &ival;
    cout << "*r: " << *r << endl;

    *r = 4201; //对r解引用
    cout << "*p: " << *pi << endl;

    //Exercise_Pointer
    int *ip, i, &rr = i; //(等价于int *ip;int i;int &rr = i;)
    i = 0;
    ip = &i;
    *ip = 10;

    cout << "rr: " << rr << endl;

    //const限定符,const对象必须初始化
    const int bufferSize = 512; //bufferSize是个常量，值不可以改变
    //bufferSize = 10;(Error)
    const int c_i = sizeof(c_i); //运行时初始化
    const int c_j = 42;		 //编译时初始化

    const int ci = c_j;
    int j = ci; //用ci初始化j，j仍可以赋值，与ci是不是常量无关

    //const仅在文件内有效
    //但是如果想在一个文件中定义，在另外一个文件共享该变量，使用extern关键字
    extern const int bufferSize2; //这样bufferSize2就可以在其他文件中被访问

    //Exercise_const
    //const int buf; //未初始化
    int cnt = 0;	//可以
    const int sz = cnt; //可以
    ++cnt;		//可以
    //++sz; //Error

    //const的引用
    const int cri = 1024;
    const int &r_cri = ci; //引用r_cri也是常量
    //r_cri = 32; //Error
    //int &r2 = cri; //Error,让非常量引用指向一个常量对象。
    int crii = 22;
    const int &r_crii = crii; //反之可以
    cout << "r_crii: " << r_crii << endl;

	//初始化和对const的引用
	int iii  = 32;
	const int &r_iii = i;
	const int &r_iii2 = 32;
	const int &r_iii3 = r_iii * 3;
	//int &r_iii4 = r_iii*2; //r_iii4是一个普通的非常量引用。

	double dval = 3.14;
	const int &r_dval = dval;

	//上述两句编译器变成如下：
	const int temp = dval;
	const int &r_dval2 = temp;
	//既然r_dval2是对临时量的引用，那么，我们可以修改下dval来看下r_dval和r_dval的输出
	dval = 2.12;
	cout << "r_dval: " << r_dval << endl;
	cout << "r_dval2: " << r_dval2 << endl; //可以发现r_dval和r_dval2并没有发生改变

    //对const的引用可能引用一个非const对象,r33不能修改不代表r3不可以修改，因此r33的值仍可能发生变化
    int i3 = 4;
    int &r3 = i3;
    const int &r33 = i3;
    r3 = 6;
    cout << "&r33 : " << r33 <<endl;

    //指针和引用类似，也可以指向常量或非常量，但是指向常量的指针不能修改其所指对象的值。
    const double pii = 3.14;
    //double *p_pii = &pii; //普通的p_pii指向了常量
    const double *p_pii = &pii; //p_ppi 是可以修改的,const 修饰的离得最近的，如果按照栈的方式把表达式，则(double *p_ppi)是个整体，const来修饰。
    double ap = 1.00;
    p_pii = &ap;
    //double *const p_pii2 = &pii;//Error p_pii2是顶层const，p_pii2不可以修改，但是所指对象的值是可以修改的，但是pii是不可以修改的，因此无法初始化

    //指针是个对象，而引用不是，因此可以把指针定义为const

    int errNumb = 0;
    int * const curErr = &errNumb; //对比109行
    const double piii = 3.45;
    const double *const pip = &piii; //对比108,109行

    //Exercise
    int i2 = 10;
    //int i4 = -1,&r4 = 0; //Error 0是const的，不能用非常量引用来指向
    int * const p_i2 = &i2;
    int * const p_i3 = 0;

    //顶层const,top-level表示指针本身是个常量，底层表示指针所指的对象是一个常量
    int i6 = 0;
    int *const p6 = &i6; //p6不可改，为顶层
    const int ci6 = 42;  //顶层（不理解）
    const int *pi6 = &i6; //pi6可改，但是指向的对象不可改。底层
    const int &r6 = i6; //用于声明引用的const都是底层

    //注意对象的拷贝操作，拷入和拷出的对象必须具有相同的底层const
    const int * const p6t = pi6;
    pi6 = p6t; //虽然p6t是个常量指针（顶层const），但是不影响本次拷贝。
    //因此pi6和p6t指向的对象都不可赋值，为read-only
    *p6 = 10; //(对于pi6和p6t，它们自恋的认为自己指向的是个常量，自己不会去改，并不代表通过其他指针来操作这个对象)
    cout << "pi6: " << *pi6 << endl;     


    //constexpr和常量表达式
    const int max_files = 20;
    const int limit = max_files + 1;
    int staff_size = 27;
    const int saz = sizeof(saz); //这个不是常量表达式，因为saz的值在运行时才确定

    constexpr int abc = sizeof(int); //sizeof是一个constexpr函数是才是正常的生命语句。
    int iiiii = 10;
    //constexpr int abcd = iiiii; //Error iiiii不是常量表达式 
    
    //而且，限定符constexpr修饰指针时只对指针有效，和指针所指对象无关。
    //int i7 = 10;
    //const int j7 = 12; //j7本身值不可改，不可改，为int * const,为顶层
    //constexpr int p_i7 = 43; //const int *类型
    //constexpr const int *p_i72 = &i7; // i7来初始化不行，因为i7为普通整型变量,
    //constexpr const int *p_i72 = &j7; //j7来初始化也不行，j7是整型常量，不是常量表达式。
    constexpr const int *p_i72 = &p_i7; 
    constexpr int *p_ij73 = &i7; //等价于int *const p_ij73，constexpr始终修饰的是指针。
    *p_ij73 = 23;
    //*p_i72 = 23;
    //p_i7 = 12;

    typedef int INT;
    INT iint;

    int i8 = 10,j8 = 11;
    auto k8 = i8+j8;
    //auto szzz = 0,pii32 = 3.14; //变量类型必须一致。

    int auto_i = 10;
    const int auto_j = 11;
    const int *p_auto_j = &auto_j;
    const int * const p_auto_j2 = &auto_j;
    //int kkk = 10222;
    //p_auto_j = &kkk;
    //cout << "auto_j: " << auto_j <<endl;


    auto test_auto_i = auto_i;
    auto test_auto_j = auto_j;
    test_auto_j = 12;
}

