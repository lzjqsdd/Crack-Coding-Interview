//类似于杨辉三角形的形式,求最小路径和
//DP ,每次保留上一层的结果
//opt,一维,O(n)

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> opt(n,0);
        opt[0] = triangle[0][0];
        for(int i=1;i<n;i++)
        {
            for(int j=i;j>=0;j--)
            {
                if(j == i)
                    opt[j] = triangle[i][j]+opt[j-1];
                else if(j == 0)
                    opt[j] = triangle[i][j]+opt[j];
                else
                    opt[j] = triangle[i][j]+min(opt[j-1],opt[j]);
            }
        }

        long minr = LONG_MAX;
        for(int i=0;i<opt.size();i++)
            if(minr > opt[i]) minr = opt[i];

        return minr;
    }
};