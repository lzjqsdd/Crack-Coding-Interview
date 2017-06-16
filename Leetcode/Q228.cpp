//题意：给定一个没有重复数字的有序数组，把这些值的取值范围一一列出来
//For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].

//用i,j表示range,如果遇到不连续，则重新开启新的区间，并把之前的区间加入到结果中
#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>result;
        if(nums.size() == 0) return result;
        int i =0,j = 0;
        while(j<nums.size()-1)
        {
            if(nums[j+1] - nums[j] == 1 ) j++;
            else
            {
                if(i == j)
                    result.push_back(to_string(nums[i]));
                else
                    result.push_back(to_string(nums[i])+"->"+to_string(nums[j]));
                j++;
                i=j;
            }
        }
        if(i == j)
            result.push_back(to_string(nums[i]));
        else
            result.push_back(to_string(nums[i])+"->"+to_string(nums[j]));
        return result;
    }
};