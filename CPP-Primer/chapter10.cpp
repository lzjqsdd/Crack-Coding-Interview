#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool cmp(const string &s1,const string&s2)
{
  return s1 > s2;
}

auto f = [](int a) -> int {cout << "lambda:" << a << endl;return 0;};

int main()
{
  vector<string> sa = {"abc","abd","acd","abcde","bcdef"};
  sort(sa.begin(),sa.end());
  for(auto it = sa.begin();it!=sa.end();++it)
    cout << *it << " ";
  cout << endl;

  sort(sa.begin(),sa.end(),cmp);
  for(auto it = sa.begin();it!=sa.end();++it)
    cout << *it << " ";
  cout << endl;

  stable_sort(sa.begin(),sa.end());
  for(auto it = sa.begin();it!=sa.end();++it)
    cout << *it << " ";
  cout << endl;

  f(3);

  stable_sort(sa.begin(),sa.end(),
              [](const string&s1,const string&s2)
              {return s1.size() < s2.size();}
              );

  int ca_x = 10;
  auto f = [&] (){cout << ca_x << endl;}; //采用隐式的引用捕获
  ca_x = 12;
  f();

  for(int i=0;i<5;i++)
  {
    //    auto f = [&](){i+=2;cout << i << endl;};
    //    f();

    //auto f = [i]() mutable {i+=2;return i;};
    //cout << f() << endl;

    //auto f = [i]() {i+=2;return i;};

  }

  vector<int> vi{1,2,3,-1,-2,-4,5,-6};
  transform(vi.begin(),vi.end(),vi.begin(),[](int i){
      if(i < 0) return -i;
      else return i;
        });
  for_each(vi.begin(),vi.end(),[](int i){cout << i << endl;});

  transform(vi.begin(),vi.end(),vi.begin(),[](int i) -> int{
      if(i < 0) return -i;
      else return i;
    });


  //插入迭代器
  list<int> lst = {1,2,3,4};
  list<int> lst2;
  list<int> lst3;
  copy(lst.cbegin(),lst.cend(),front_inserter(lst2));

  for(list<int>::iterator it = lst2.begin();it!=lst2.end();++it)
    cout << *it << endl;
  
  istream_iterator<int> in(cin),eof; //使用流迭代器求输入数据的和
  cout << accumulate(in,eof,0) << endl;

  //用copy来打印vector数据
  vector<int> vint;
  ostream_iterator<int> oit(cout,"\n");
  copy(vint.begin(),vint.end(),oit);
