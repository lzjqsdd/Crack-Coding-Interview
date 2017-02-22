//Maximum Product Subarray
// [2,3,-2,4] 连续最大的乘积
// 由于可能出现负数，所以负的最大乘以一个负数肯定更大。DP算法，每一步计算一个最大值，计算一个最小值
// optMax[i] = max{ nums[i] * optMax[i-1], nums[i]*optMin[i-1],nums[i]};
// optMin[i] = min{ nums[i] * optMax[i-1], nums[i]*optMin[i-1],nums[i]};

class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int maxp = nums[0],minp = nums[0],result = nums[0];
        
        for(int i=1;i<nums.size();++i)
        {
            int pro1 = nums[i]*maxp;
            int pro2 = nums[i]*minp;
            maxp = max(max(pro1,pro2),nums[i]);
            minp = min(min(pro1,pro2),nums[i]);
            if(maxp > result) result = maxp; //保留规划过程中的最大值，最后一个maxp并非是最大的。Error
        }
        return result;
    }
};