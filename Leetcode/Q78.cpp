//给定一组不同的数，打印子集
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> tmp;
        solve(false,1,nums,tmp);
        solve(true,1,nums,tmp);
        return result;
    }

    void solve(bool flag,int len,vector<int>&nums,vector<int>tmp)
    {
        if(flag) tmp.push_back(nums[len]);
        if(len == nums.size())
        { result.push_back(tmp); return;}

        solve(false,len+1,nums,tmp);
        solve(true,len+1,nums,tmp);
    }

    vector<vector<int>> result;
};