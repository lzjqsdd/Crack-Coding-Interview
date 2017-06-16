//398. Random Pick Index
//题意：给一堆数(可能有重复),给定目标数target,每次随机输出等于target的索引，对与同一个数每次输出的概率相同
//数据非常大，耗费空间会超过空间限制

//把符合target的作为一个数据流不断输入，使用水塘采样

class Solution
{
  public:
    Solution(vector<int> nums):nums(nums)
    {
    }

    int pick(int target)
    {
        int count = 0;
        int res = -1;
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i] != target) continue;
            count++;
            if(rand() % count == 0) res = i; //rand()%x返回的是[0,x]之间的整数,等于0说明返回的概率为1/count,选择streaming末尾的数，否则保持之前的数
        }
        return res;
    }
private:
    vector<int> nums;
};























/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */

class Solution {
public:
    Solution(vector<int> nums): v(nums) {}
    
    int pick(int target) {
        int cnt = 0, res = -1;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] != target) continue;
            ++cnt;
            if (rand() % cnt == 0) res = i;
        }
        return res;
    }
private:
    vector<int> v;
};