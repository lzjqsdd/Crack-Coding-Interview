#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

int main()
{
  vector<int> v_int;
  for(int i=0;i<10;i++)
    v_int.push_back(i);

  //vector<int>::reverse_iterator rit; //反向容器的使用，赞！
  //for(rit = v_int.rbegin();rit!=v_int.rend();++rit)
  //  cout << *rit << endl;

  //for(auto rit = v_int.rbegin();rit!=v_int.rend();++rit)
  //  cout << *rit << endl;

  //vector<int> v_int2(v_int.begin()+1,v_int.end()-1);

  //for(auto rit = v_int2.rbegin();rit!=v_int2.rend();++rit)
  //  cout << *rit << endl;

  vector<double> v_double(10,0.12);
  vector<int> v_int3(v_double.begin(),v_double.end()); //元素类型可以不一样  

  for(auto rit = v_int3.rbegin();rit!=v_int3.rend();++rit)
    cout << *rit << endl;

  array<int ,10> ia1;

  vector<string> v_s1(10,"hello");
  vector<string> v_s2(10,"hello2");
  vector<string>::iterator it1 = v_s1.begin();
  it1+=3;
  v_s1.swap(v_s2);
  cout << *it1 << *(it1+1) << endl; //交换后迭代器仍然指向原来的元素，不过所属容器毕竟发生变化
 
  vector<string>::iterator iti = v_s1.begin()+3;
  v_s1.insert(iti,{"a","b","c"}); //如果还用交换前的iterator,插入会出错
  for(auto its = v_s1.begin();its!=v_s1.end();++its)
    cout << *its << endl;

  cout << "front" << v_s1.front() << endl <<  "back:" << v_s1.back() << endl;


  string s = "aabbccdefgh";
  sort(s.begin(),s.end());
  auto pos_s = unique(s.begin(),s.end());
  s.erase(pos_s,s.end());
  cout << "s:" << s << endl;

}
