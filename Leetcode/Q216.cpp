//同Q40
//题意：从1~9中选择k个数，使得其和等于目标n.相比于Q40,多了k的限制，但是不存在相同的组合

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        return solve(1,n);
    }

    vector<vector<int>> solve(int cur,int n,int k)
    {
        vector<vector<int>> result;
        for(int i=cur;i<=9;++i)
        {
            if(i > n) return;
            else if(i == n && k==1)
            {
                result.push_back(vector<int>(1,i));
            }
            else // i<n
            {
                vector<vector<int>> res = solve(i+1,n-i,k-1);
                for(auto re:res)
                {
                    re.push_back(i);
                    result.push_back(re);
                }
            }
        }
        return result;
    }
};