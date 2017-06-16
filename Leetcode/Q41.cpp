//题意：给定一个未排序的数组，找第一个缺失的正整数
//要求使用O(n)时间，O(1)空间


//题目并未要求maintain 数组的值。
//缺失代表着这些数应该是连续的，给每个数找回自己的位置，1～k个数，缺失的数范围在1~k+1
//交换完应该是[1,2,3,4....];

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        while(i < n)
        {
            while(nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i]-1]) //第一个元素存1
                swap(nums[i],nums[nums[i]-1]);
            i++;
        }
        for(i = 0;i<n;++i)
            if(nums[i] != i+1) return i+1;
            
        return n+1; //如果前面都满足，则补最后一个
    }
};