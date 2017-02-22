#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/*
int main()
{
      int n,m;
      while(cin>>n>>m)
      {
            vector<string> sv;
            for(int i=1;i<=n;i++)
            {
                  sv.push_back(std::to_string(i));
            }
            sort(sv.begin(),sv.end());
            cout<<sv[m-1]<<endl;
      }
      return 0;
}

*/


int main()
{
      int n,m;
      while(cin>>n>>m)
      {
            string ss = std::to_string(n);
            int len =ss.size();
            int num = 0;
           	for(int i = 0;i<len;i++)
            {
                  num = num+pow(10,i);
            }
            int modd = m%num; //第几段的第几个
            int shang = m/num; //第几段,开头就是几。
            for(int i=0;i<len;i++)
            {
                  if(modd-pow(10,i) > 0)
                        modd = modd-pow(10,i);
                  else
                  {
                        cout << modd+pow(10,i-1)<<endl;
                        break;
                  }
                  
            }
      }
      return 0;
}
