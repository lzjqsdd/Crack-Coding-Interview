//给定01序列，找出最长的连续的1.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int num = 0,max=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] == 1) num++;
            else{
                if(num > max) max = num;
                num = 0;
            }
        }
        return max;
    }
};