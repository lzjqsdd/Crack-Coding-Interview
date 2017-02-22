//希尔排序
//插入排序的改进版
//跳跃分组，比如147一组，258一组，369一组
//对每个分组进行插入排序
//增量公式为increment = increment/3+1
//
#include <iostream>
#include <vector>
using namespace std;

//把数组分为两半，左侧已经是有序的，每次取无序的第一个，判断和有序的大小，查找需要插入的位置。

int main()
{
    //vector<int> number = {-1,3,3,5,61,23,8,10,11,29};
    vector<int> number = {10,9,8,7,6,5,4,3,2,1,0};


    int increment = number.size();
    while(increment > 1)
    {
        increment = increment/3+1;
        for(int i=increment;i<number.size();i+=increment)
        {
            int tmp = number[i];
            int j;
            for(j=i-increment;j>=0;j-=increment)
            {
                if(number[j] > tmp) number[j+increment] = number[j];
                else  break;
            }
            number[j+increment] = tmp; //不断后移，j+1的位置是空的，等待插入
        }
    }



    for(int i=0;i<number.size();i++)
        cout << number[i] <<"," ;

    cout << endl;
}
