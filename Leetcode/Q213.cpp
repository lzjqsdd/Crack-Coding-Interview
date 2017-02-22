//HouseRobber II
//本题的房子是个环状，同样考虑动态规划，第一次考虑第一个而不考虑最后一个，第二次不考虑第一个而考虑最后一个，输出两次动态规划的最大值


class Solution {
public:
    int rob(vector<int>& nums) {

        if(nums.size()==1) return nums[0];
        else if(nums.size() == 2) return max(nums[0],nums[1]);

        vector<int> opt1(nums.size(),0);
        opt[0] = nums[0];
        opt[1] = max(nums[0],nums[1]); //相邻只能robbe一个
        for(int i=2;i<nums.size()-2;i++)
        {
            opt[i] = max(opt[i-2]+nums[i],opt[i-1]);
        }
        int max1 = opt[nums.size()-2];
        
        //第二次DP,从第二个房子开始
        opt[1] = nums[1];
        opt[2] = max(nums[1],nums[2]);
        for(int i=3;i<nums.size()-1;i++)
            opt[i] = max(opt[i-2]+nums[i],opt[i-1]);
        
        int max2 = opt[nums.size()-1];
        return max(max1,max2);
    }
};