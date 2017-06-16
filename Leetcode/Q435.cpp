//题意：给定一组区间，求移除最少的区间使得剩下的区间没有重叠
//思路：可以转换为如何让更多的区间没有重叠。参考卜东波老师贪心章节上课区间安排的雷子。
//Greedy，每次贪心选择结束区间（下课最早的），假设有最优解选择的不是结束最早的，那么把第一个改为下课最早的依然不改变最优解。
//所以每次选择结束最早的区间

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        if(intervals.size() == 0) return 0;
        auto cmp = [](const Interval& iv1,const Interval&iv2){return iv1.end < iv2.end;};
        sort(intervals.begin(),intervals.end(),cmp);
        int count = 1;
        int cur = 0;
        for(int i=1;i<intervals.size();++i)
        {
            if(intervals[i].start >= intervals[cur].end) //没有重叠
            {
                count++; cur = i;
            }
        }
        return intervals.size()-count;
    }
};