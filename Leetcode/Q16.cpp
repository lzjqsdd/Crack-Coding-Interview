//题意：给定一个n个元素的数组，找出三个数，其和最接近目标值S。
//是Q15的变种
//思路：直接暴力肯定超时，考虑有序数组中找两个数的和为目标值。可以在前后置两个指针。

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        if(nums.size() <= 3) return accumulate(nums.begin(),nums.end(),0);

        sort(nums.begin(),nums.end());
        long dif = LONG_MAX; //记录每一轮的diff.
        for(int k=0;k<nums.size()-2;k++)
        {
            long diff = LONG_MAX;
            int i = k+1;
            int j = nums.size()-1;
            while(i < j)
            {
                long sum = nums[k]+nums[i]+nums[j];
                long difftmp = sum - target;
                if(abs(difftmp) < abs(diff))
                {
                     diff = difftmp;
                }
                //else break; //如果差距扩大就不再查找。

                if(sum > target) j--;
                else if(sum < target) i++;
                else return target; //如果刚好等于target，最合适的值。
            }

            if(abs(dif) > abs(diff)) dif = diff;
        }


        return (dif+target);
    }
};