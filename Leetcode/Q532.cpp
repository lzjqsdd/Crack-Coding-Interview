//使用首尾指针
//属于two-sum的变形
//Array ,属于two-Pointers


class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        size_t n = nums.size();
        int s=0,t=1,res=0;
        while(s < t && t < n)
        {
            if(nums[t] - nums[s] < k) t++; //如果差值小于k,后移尾指针
            else
            {
                if(nums[t] - nums[s] == k)
                {
                    if(s == 0 || nums[s] != nums[s-1]) res++; //确保相同的只计算一次
                }
                s++;
                if(s == e) e++;
            }
        }
        return res;
    }
};