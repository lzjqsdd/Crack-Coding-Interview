//题意：给定一个matrix，由0/1组成，找出其中最大的由1组成的正方形
//Medium
//Dynamic Programming

//由于只考虑正方形，所以DP条件是判断能够包围更小的正方形
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int opt[m][n]; //表示当前原始可以组成的正方形的边长
        int maxa = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                if(matrix[i][j] == '0') opt[i][j] = 0;
                else
                {
                    opt[i][j] = min(min(opt[i-1][j],opt[i][j-1]),opt[i-1][j-1]) + 1;
                }
                if(maxa < opt[i][j]) maxa = opt[i][j];
            }
        return maxa*maxa;
    }
};

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int opt[m][n][4]; //维护两个边的起始位置(ws,we,hs,he)
        int maxa = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                if(matrix[i][j] == '1')
                {
                    opt[i][j][0] = opt[i][j][1] = j;
                    opt[i][j][2] = opt[i][j][3] = i;

                    if(i-1>=0 && matrix[i-1][j]=='1')
                        opt[i][j][2] = opt[i-1][j][2]; //改变起点
                    if(j-1>=0 && matrix[i][j-1] == '1')
                        opt[i][j][0] = opt[i][j-1][0];
                    if(i-1>=0 && j-1>=0 && matrix[i-1][j-1] == '1')
                    {
                        int w = max(opt[i-1][j-1][0],opt[i][j][0]);
                        int h = max(opt[i-1][j-1][2],opt[i][j][])
                    }
                }
            }
               
    }
};



//opt[i][j] 表示当前点所在的正方形的最大的边长

//考虑2*2中包含三个1*1
//3*3大小的正方形，正上方为2*2,左侧位2*2,左上角也为2*2，才能组成3*3的，才能把所有的9个各自填充
//同理n*n
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m == 0) return 0;
        int n = matrix[0].size();
        int opt[m][n]; //表示当前原始可以组成的正方形的边长
        int maxa = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                if(matrix[i][j] == '0') opt[i][j] = 0;
                else
                {
                    if(i-1>=0 && j-1>=0)
                        opt[i][j] = min(min(opt[i-1][j],opt[i][j-1]),opt[i-1][j-1]) + 1;
                    else
                        opt[i][j] = 1;
                }
                if(maxa < opt[i][j]) maxa = opt[i][j];
            }
        return maxa*maxa;
    }
};