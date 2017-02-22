#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
  string fis = "/home/lzjqsdd/a.txt";
  string fos = "/home/lzjqsdd/b.txt";
  //fstream strm(s.c_str());
  //strm.close();

  ifstream in(fis.c_str());
  ofstream out(fos.c_str());
  int a = 0;
  if(in && out){
    while(in >> a)
      out << a << endl;
    //cout << a << endl;
  }

  string is = "abcdedf -12345";
  string sx;
  istringstream sis(is);
  sis >> sx;
  cout << "sx:" << sx << endl;
  ostringstream sos;//不需要构造参数
  sos << sx << endl; //将sx输出到流sos中
  cout << "sos.str:" << sos.str() << endl; ///打印sos中的内容

  sos.clear();
  double da = -2.15;
  string sa = "try";
  sos << da << sa;
  cout << sos.str() << endl; //轻松实现itoa

  int aa;
  sis >> aa;
  cout << aa << endl;
}
