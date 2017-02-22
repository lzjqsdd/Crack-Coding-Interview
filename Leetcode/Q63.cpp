//63. Unique Paths II
//相比与62题，在格子中增加了障碍物，同样使用DP，障碍物处路径数为0

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        int opt[n]; //不使用矩阵，用行记录即可
        int tmp[m]; //第一列记录，因为如果有障碍物，接下来的位置为0

        for(int i=0;i<m;i++)
        {
            if(obstacleGrid[i][0] == 1)
            {
                while(i<m) tmp[i++] = 0;
            }
            else
                tmp[i] = 1;
        }

        for(int j=0;j<n;j++)
        {
            if(obstacleGrid[0][j] == 1)
            {
                while(j < n) opt[j++] = 0;
            }
            else
                opt[j] = 1;
        }
        for(int i=1;i<m;i++)
        {
            opt[0] = tmp[i];
            for(int j=1;j<n;j++)
            {
                if(obstacleGrid[i][j] == 1) opt[j] = 0;
                else
                    opt[j] = opt[j]+opt[j-1];
            }
        }
        return opt[n-1];

    }
};