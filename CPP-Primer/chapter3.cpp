#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	/*按单词读取
	while(cin >> s)
	{
		cout << s << endl;} */

	//按行读取
	//while(getline(cin,s))
	//	cout << s << endl;


	/* string s2;
	cin >> s >> s2;
	if(s > s2)
		cout << s <<  endl;
	else
		cout << s2 << endl;
	*/

  /*
	string s2;
	string s_result;
	while(cin >> s2 && s2!="end")
		s_result +=  s2;
	cout << s_result << endl;
  */

  //这种用非常量的方式定义数组在gcc下可以通过，属于编译器扩展，但是实际数组定义必须使用常量来定义
  /*
  int n  = 5;
  int a[n];
  a[0] = 10;
  a[1] = 12;
  a[2] = 12;
  a[3] = 12;
  a[4] = 12;
  for(unsigned int i = 0;i<n;i++)
	  cout << a[i] << endl;
  */

  //但是如果采用如下方式会报错
  //int n2 = 5;
  //int a2[n2] = {1,2,3,4,5};

  //const int n2 = 5;
  //int a2[n2] = {1,2,3,4,5};

  //int *pts[10];  //定义了一个长度为10的元素类型为int*的数组。
  //int (*ptr)[10]; //定义了一个指向一个长度为10的数组的指针。
  //int (&ptrr)[10];
  //int &ref[10]; Error,引用不是对象

  /*
  int a[5] = {1,2,3,4,5};
  int *p1 = &a[0];
  int *p2 = &a[2];
  p1 += p2 - p1;
  cout << (*p1)  << endl;
  p2 += p1 - p2;
  cout << (*p1)  << endl;
  */

  //int i = 0;
  //cout << i << "--" << ++i << endl; //结果可能是未定义


  int i = 1;
  if((i) || ++i)
    cout << i << endl;

	return 0;
}
