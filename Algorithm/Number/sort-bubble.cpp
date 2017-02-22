#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> number = {-1,3,3,5,61,23,8,10,11,29};
    for(int i=1;i<number.size();i++)
        for(int j=1;j<i;j++)
        {
            if(number[j] > number[i]) //把大的冒泡到最后
            {
                swap(number[i],number[j]);
            }
        }


    for(int i=0;i<number.size();i++)
        cout << number[i] <<"," ;

    cout << endl;
}
