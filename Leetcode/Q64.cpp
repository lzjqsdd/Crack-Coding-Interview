//题目意思：给定一个二维数组，元素非负。求一条从左上到右下的路径，使得路径上的和最小
//因为元素非负，并且和最小。最终问题的最优解包含子问题的最优解。
//不是贪心，如果因为某一步贪心，选择了最小，而该位置可通往的路径的元素很大，导致之后的和可能会变大
//采用DP,opt[i][j]表示从左上角到达matrxi[i][j]时最小的和。到达（i,j)两种方式，一种从(i-1,j)，
//一种从(i,j-1)
// opt[i][j] = min{opt[i-1][j],opt[i][j-1]} + matrix[i][j]
// 初始化 opt[i][0] = matrix[i][0],opt[0][j] = matrix[0][j]

//时间复杂度O(n^2)
//空间优化：opt[j] 表示遍历到i层时的最优值。opt[0] = opt[0] + nums[i]; opt[j] = min{opt[j],opt[j-1]}

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();
        vector<int> opt(grid[0].begin(),grid[0].end());
        for(int i=0;i<m;++i)
        {
            opt[0] = opt[0] + grid[i][0];
            for(int j=1;j<n;j++)
                opt[j] = min(opt[j],opt[j-1]) + grid[i][j];
        }
        return opt[m-1][n-1];
    }
};


[1,2,3,4,1]
[8,1,2,6,11]
[1,4,2,1,1]

1,