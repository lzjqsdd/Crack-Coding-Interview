//选择排序 ，每次选择序列中最小的放到首位。
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> number = {-1,3,3,5,61,23,8,10,11,29};

    for(int i=0;i<number.size()-1;i++)
    {
        int k = i;
        int minn = number[i];
        for(int j=i+1;j<number.size();j++)
        {
            if(minn  > number[j]) 
            {
                k = j;
                minn = number[j];
            }
        }
        swap(number[k],number[i]);
    }

    for(int i=0;i<number.size();i++)
        cout << number[i] <<"," ;

    cout << endl;
}
