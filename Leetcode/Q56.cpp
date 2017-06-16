//题目描述：
//合并区间[1,3],[2,6],[8,10],[15,18] 合并为 [1,6] [8,10],[15,18]

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
 };

static bool compare(const Interval&ia,const Interval& ib)
{
    return ia.start < ib.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size() < 1) return intervals;
        vector<Interval> result;
        sort(intervals.begin(),intervals.end(),compare);
        Interval in = intervals.front();
        for(auto it = intervals.begin()+1;it!=intervals.end();++it)
        {
            if((*it).start <= in.end && (*it).end > in.end)
            {
                in.end = (*it).end;
            }
            else if((*it).start > in.end)
            {
                result.push_back(in);
                in.start = (*it).start;
                in.end = (*it).end;
            }
        }
        return result;

    }
};

int main()
{
    return 0;
}