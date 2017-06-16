//题目描述：
//给定一个下毒时间t，每次下毒会持续k秒，输入为一组下毒的时间，输出总的中毒的时间
//下毒时间为增序
//O(n)
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int etime = 0; //表示每次结束中毒的时间
        int totaltime = 0;
        for(auto it = timeSeries.begin();it!=timeSeries.end();++it)
        {
            if(*it >= etime)
            {
                totaltime += duration;
                etime = *it + duration;
            }
            else
            {
                totaltime += (*it + duration - etime);
                etime = *it + duration;
            }
            cout << totaltime << endl;
        }
        return totaltime;
    }
};

int main()
{
    vector<int> test = {1,2,3,4,5,8};
    int n = 3;
    Solution s;
    s.findPoisonedDuration(test,n);
}