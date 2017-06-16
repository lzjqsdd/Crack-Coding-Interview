//376. Wiggle Subsequence（摆动序列问题）
//题意：给定一组序列，找出最长的摆动序列。摆动序列是指：一大一小交替出现。

//[1,17,5,10,13,15,10,5,16,8]
//思路：(1)动态规划 
//定义opt[n][2] , opt[i][0]表示当前元素作为峰顶的最长序列值，opt[i][1]表示当前元素作为谷底的最长序列的值
//如果a[i]小于a[i-1],那么a[i]应该作为谷底，则opt[i][0] = opt[i-1][1] + 1;opt[i][1] = opt[i-1][1]
//反之  opt[i][1] = opt[i-1][0]

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        vector<vector<int>> opt(nums.size(),vector<int>(2));
        opt[0][0] = opt[0][1] = 1;
        for(int i = 1; i<nums.size(); ++i)
        {
            if(nums[i] < nums[i-1])
            {
                opt[i][0] = opt[i-1][1] + 1;
                opt[i][1] = opt[i-1][1]; //当前仍然为峰（替换了原始序列的尾部的峰)
            }
            else if(nums[i] > nums[i-1])
            {
                opt[i][1] = opt[i-1][0] + 1;
                opt[i][0] = opt[i-1][0];
            }
            else //相同元素不变
            {
                opt[i][0] = opt[i-1][0];
                opt[i][1] = opt[i-1][1];
            }
        }
        return max(opt[nums.size()-1][0],opt[nums.size()-1][1]);
    }
};


//思路(2):Greedy
//序列的摆动只和前一个元素相关大小及其所出的(峰或者谷)相关。
//从当前元素开始，如果是一个元素，无所谓升降。但是往后走，我们希望尽可能多加入元素。对于有下降趋势的，并且持续下降(无法摆动)
//显然可以使用更小的值来代替摆动序列最后的值，为上升提供更大的可能性。同理，对于持续上升的序列，用更大的值代替序列末尾，以寻求
//更大的可能性来降低序列

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        vector<int> result;
        int k = 0;
        while(k < nums.size() && nums[k] == nums[k+1]) k++; //去除首部重复元素以获得初始摆动方向
        
        if(k < nums.size()) result.push_back(nums[k]);
        
        int flag = 0;
        if(k+1 < nums.size())
        {
            result.push_back(nums[k+1]);
            if(nums[k] < nums[k+1]) flag = 1;
            else  flag = -1;
        }
        for(int i=k+1;i<nums.size();++i)
        {
            if(nums[i] > result.back())
            {
                if(flag == 1)
                {
                    result.pop_back();
                    result.push_back(nums[i]);
                }
                else
                {
                    result.push_back(nums[i]);
                    flag = 1;
                }
            }
            else if(nums[i] < result.back())
            {
                if(flag == -1)
                {
                    result.pop_back();
                    result.push_back(nums[i]);
                }
                else
                {
                    result.push_back(nums[i]);
                    flag = -1;
                }
            }
        }
        return result.size();
    }
};