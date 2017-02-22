#include <iostream>
#include <vector>
using namespace std;

//把数组分为两半，左侧已经是有序的，每次取无序的第一个，判断和有序的大小，查找需要插入的位置。

int main()
{
    //vector<int> number = {-1,3,3,5,61,23,8,10,11,29};
    vector<int> number = {6,5,4,3,2,1};


    int k = 0;
    for(int i=1;i<number.size();i++)
    {
        int tmp = number[i];
        int j;
        for(j=i-1;j>=0;j--)
        {
            if(number[j] > tmp) number[j+1] = number[j];
            else  break;
        }
        number[j+1] = tmp; //不断后移，j+1的位置是空的，等待插入
    }



    for(int i=0;i<number.size();i++)
        cout << number[i] <<"," ;

    cout << endl;
}
