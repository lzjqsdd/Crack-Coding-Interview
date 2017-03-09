#include<iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> a = {4,3,2,7,8,2,3,1};  
    vector<int> result;

    for(int i=0;i<a.size();++i)
    {
        int x = a[i] - 1;
        while(a[x] != a[i]-1)
        {
            a[i] = a[x];
            a[x] = x;
            x = a[i] - 1;
        }
    }
    for(auto i:a) cout << i << ",";
    cout << endl;    
}