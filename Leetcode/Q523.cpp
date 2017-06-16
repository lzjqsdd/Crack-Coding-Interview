//DP
//题目意思:求是否存在连续子序列的和是k的倍数。子序列至少为2
//思路：
//每次记录sum%k，不断向后计算，如果sum出现过说明存在这样的序列

/*
@ohuohuo This is one of those magics of reminder theorem :)

(a+(n*x))%x is same as (a%x)

For e.g. in case of the array [23,2,6,4,7] the running sum is [23,25,31,35,42] and the reminders are [5,1,1,5,0]. 
We got reminder 5 at index 0 and at index 3. 
That means, in between these two indexes we must have added a number which is multiple of the k. 
Hope this clarifies your doubt :)

*/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int,int> mmap;
        mmap[0] = -1;
        int sum = 0;
        for(int i=0;i<nums.size();++i)
        {
            sum += nums[i];
            if(k != 0) sum %= k;
            map<int,int>::iterator it = mmap.find(sum);
            if(it != mmap.end()) //如果之前出现过，说明两个之间的数的和肯定是k的倍数
            {
                if(i - it->second > 1) //说明序列长度至少为2
                    return true;
            }
            else
                mmap[sum] = i;
        }
        return false;
    }
};