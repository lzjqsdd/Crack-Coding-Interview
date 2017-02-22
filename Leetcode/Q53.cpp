//Maximum Subarray
//[-2,1,-3,4,-1,2,1,-5,4]
//求和最大的连续的子序列
//DP

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxp = nums[0],result = nums[0];
        
        for(int i=1;i<nums.size();++i)
        {
            maxp = max(nums[i]+maxp,nums[i]);
            if(maxp > result) result = maxp;
        }
        return result;
    }
};