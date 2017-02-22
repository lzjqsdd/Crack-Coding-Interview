//Unique Paths
//从左上走到右下，每次只能向右或者向下，有多少中不同的路径
//DP
//opt[i][j]表示从左上角走到(i,j)格子的路径数
//opt[0][j] = 1; //横着一条
//opt[i][0] = 1; //纵着一条
//opt[i][j] = opt[i-1][j]+opt[i][j-1] //既可以来自上面也可以来自左侧，两种方式之和
// ----------------------
// |    1 1 1 1 1       |
// |    1 2 3 4 5       |
// |    1 3 6 10 15     |
// |    1 4 10 20 35    |
// ----------------------

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int opt[n];
        for(int i=0;i<n;i++) opt[i] = 1;
        for(int i=1;i<m;i++)
        {
            opt[0] = 1;
            for(int j=1;j<n;j++)
            {
                opt[j] = opt[j]+opt[j-1];
            }
        }
        return opt[n-1];
    }
};