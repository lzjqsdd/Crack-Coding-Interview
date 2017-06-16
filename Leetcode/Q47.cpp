//题意：同46，求全排列，但是该组数据中存在相同的数
//在46基础上改，应该是加入前导时判断是不是该前导已经加入过（即相邻的有相同的，则只取一个），
//而不是把相同的列为一组来持续加入前导，这样11总是挨着，但112可能出现121.



class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
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
                if(i>0 && nums[i] == nums[i-1]) continue; //如果相邻的相同，那么以哪个作为前导都是同样的结果，所以相同的话不再作为前导。
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