//题意：给出一个含不同元素的数组，给出他们全部的全排列。按照从小到大给出。
//全排列的个数位n!个
//递归方式:
//
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() == 0) return {{}};
        sort(nums.begin(),nums.end());
        vector<int> res;
        per(nums,res);
        return result;
    }

    void per(vector<int>&nums,vector<int>&res)
    {
        if(nums.size() == 1)
        {
            res.push_back(nums[0]);
            result.push_back(res);
        }
        else
        {
            for(int i = 0;i<nums.size();++i)
            {
                vector<int>next(nums);
                vector<int>nextres(res);
                nextres.push_back(nums[i]);
                next.erase(next.begin()+i);
                per(next,nextres);
            }
        }
    }
private:
    vector<vector<int>> result;
};