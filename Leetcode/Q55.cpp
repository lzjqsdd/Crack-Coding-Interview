//题意：给定一个数组，元素值表示该元素可以jump的步数，问是否可以从初始元素jump到最后的元素上


//TLE
class Solution {
public:
    bool canJump(vector<int>& nums) {
        return canJump(nums,0);
    }
    bool canJump(vector<int>&nums,int i) //i表示当前位置
    {
        if(i == nums.size()-1) return true;
        bool result = false;
        for(int k = 1;k<=nums[i];++k){
            if(i+k < nums.size())
            {
                result |= canJump(nums,i+k);
                if(result) break;
            }
        }
        return result;
    }
};


//如果序列里没有0，一步步走肯定都能到。
//所以这道题关键是0的处理，如果可以跳过0的位置，就可以规约到更小的问题上。
//遍历，把每个位置最远可以到达的位置标记起来。max标记当前可以达到的最远的位置

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() <= 1) return true;
        int maxpos = 0;
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i] == 0)
            {
                if(maxpos <= i && i!=nums.size()-1) return false;
            } 
            if(maxpos < i+nums[i]) maxpos = i+nums[i];
        }
        return true;
    }
};
//[2,0,0]