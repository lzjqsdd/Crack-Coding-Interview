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


//第二遍，和15题类似，但是求的是和target值相差最小的sum
//每个测试用例只有唯一的解

//思路，排序+two-pointer,每轮记录最小的diff
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3) return accumulate(nums.begin(),nums.end(),0);

        sort(nums.begin(),nums.end());
        int diff = INT_MAX;
        for(int k = 0;k<nums.size()-2;++k) //选择第一个元素
        {
            int i = k+1;
            int j = nums.size()-1;
            //找出含nums[k]时，最接近的和,如果有等于target，直接return
            int sum = target - nums[k];
            while(i < j)
            {
                int s = nums[i] + nums[j];
                int tmpdiff = s - sum;
                if(abs(diff) > abs(tmpdiff))
                    diff = tmpdiff; //不用向上次的方法设置内层的diff

                if(s > sum) j--;
                else if(s < sum) i++;
                else return target; 
            }
        }
        return diff + target;
    }
};