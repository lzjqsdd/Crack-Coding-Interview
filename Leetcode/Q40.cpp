//Combination Sum II
//题意：给定一个数组nums和目标T,给出所有可能的组合，使得这些组合的sum等于target.(结果中不能包含重复的),所有的数都是正整数

//[10, 1, 2, 7, 6, 1, 5]
//14:17

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end(),greater<int>()); //从大到小排序
        //for(auto x:candidates) cout << x << ",";
        //cout << endl;`
        return solve(candidates,target,0,candidates.size()-1);
    }

    vector<vector<int>> solve(vector<int>& nums,int target,int l,int r)
    {
        cout << "[" << l << "," << r << "]" << endl;
        vector<vector<int>> result;
        if(l == r && nums[l] == target)
        {
            result.push_back(vector<int>(1,nums[l]));
            return result;
        } 
        for(int i = l;i<=r-1;++i) //直到错哪里了，这里循环已经把小问题的规模计算了，但是迭代计算时依然要考虑这些小规模的问题
        {
            if(target > nums[i])
            {
                vector<vector<int>> res = solve(nums,target-nums[i],l+1,r);
                for(auto re:res)
                {
                    re.push_back(nums[i]);
                    result.push_back(re);          
                }
            }
            //对于相同的元素，如果不包含该元素，则会出现重复元素
            if(i+1 <= r && nums[i] == nums[i+1]) continue;
            vector<vector<int>> res2 = solve(nums,target,l+1,r);
            for(auto re:res2)
                result.push_back(re);
        }
        return result;
    }
};
*/

//修改版本2 //无法解决重复问题
/*
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end(),greater<int>()); //从大到小排序
        //for(auto x:candidates) cout << x << ",";
        //cout << endl;`
        return solve(candidates,target,0);
    }

    vector<vector<int>> solve(vector<int>& nums,int target,int l)
    {
        vector<vector<int>> result;
        if(l >= nums.size()) return result;

        if(target == nums[l])
        {
            result.push_bacK(vector<int>(1,nums[l]));
            return result;
        }
        if(target > nums[l]) //考虑当前元素
        {
            vector<vector<int>> res = solve(nums,target-nums[l],l+1);
            for(auto re:res)
            {
                re.push_back(nums[l]);
                result.push_back(re);
            }
        }

        if(l+1 < nums.size() && nums[l] != nums[l+1]) //不考虑当前元素,但是不能重复
        {
            vector<vector<int>> res = solve(nums,target,l+1);
            for(auto re:res)
            {
                result.push_back(re);
            }
        }
        return result;
    }
};
*/

//AC Answer - Backtraciing
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end(),greater<int>()); //从大到小排序
        //for(auto x:candidates) cout << x << ",";
        //cout << endl;`
        return solve(candidates,target,0);
    }

    vector<vector<int>> solve(vector<int>& nums,int target,int l)
    {
        vector<vector<int>> result;
        for(int i = l;i<nums.size();++i)
        {
            if(i-1 >=0 && i>l && nums[i] == nums[i-1] ) continue; //每次for循环加入一个值，同时target变小，所以这个值不能重复
            if(target < nums[i]) continue;
            else if(target == nums[i])
            {
                result.push_back(vector<int>(1,nums[i]));
            }
            else
            {
                vector<vector<int>> res = solve(nums,target-nums[i],i+1);
                for(auto re:res)
                {
                    re.push_back(nums[i]);
                    result.push_back(re);
                }   
            }
        }
        return result;
    }
};

int main()
{
    vector<int> test = {10,7,6,5,2,1,1};
    Solution s;
    s.combinationSum2(test,8);
}





//Answer
class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) 
    {
        vector<vector<int>> res;
        sort(num.begin(),num.end());
        vector<int> local;
        findCombination(res, 0, target, local, num);
        return res;
    }
    void findCombination(vector<vector<int>>& res, const int order, const int target, vector<int>& local, const vector<int>& num)
    {
        if(target==0)
        {
            res.push_back(local);
            return;
        }
        else
        {
            for(int i = order;i<num.size();i++) // iterative component
            {
                if(num[i]>target) return;
                if(i&&num[i]==num[i-1]&&i>order) continue; // check duplicate combination
                local.push_back(num[i]),
                findCombination(res,i+1,target-num[i],local,num); // recursive componenet
                local.pop_back();
            }
        }
    }
};