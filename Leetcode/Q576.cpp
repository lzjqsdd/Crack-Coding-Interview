//移动足球。给定m*n大小的各自，足球初始位置i,j,每次可以上下左右移动。
//在不超过N次的条件下把球移动到格子之外。问有多少种移动方法.
//N最多为50，格子大小最大为50*50

const int d[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int N = 60;
const int MOD = 1e9 + 7;
int dp[N][N][N];

//dp[i][j][k] 表示在(i,j)位置开始最多走k部能够出边界的路径数
//初始化dp[i][j][1] 分别计算每个位置走1步可以出边界的路径数
//状态转移方程
//dp[i][j][k] += dp[x][y][k-1],if (i,j)->(x,y)且(x,y)还在边界内
//或者dp[i][j][k]++; if (i,j)->(x,y)  且 (x,y)已经在边界外

//大神的代码
class Solution {
public:
    int findPaths(int m, int n, int N, int u, int v) {
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j][1] = 0;
                for (int k = 0; k < 4; ++k) {
                    int x = i + d[k][0];
                    int y = j + d[k][1];
                    if (!(x >= 0 && x < m && y >= 0 && y < n)) ++dp[i][j][1];
                }
            }
        }
        for (int u = 2; u <= N; ++u) {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    dp[i][j][u] = 0;
                    for (int k = 0; k < 4; ++k) {
                        int x = i + d[k][0];
                        int y = j + d[k][1];
                        if (x < 0 || x >= m || y < 0 || y >= n) {
                            ++dp[i][j][u]; //一步已经出界
                            dp[i][j][u] %= MOD;
                        } else { //否则,(i,j) -> (x,y).如果(i,j)还在界内，则路径数可以加上(x,y)在u-1步能出界的数目
                            dp[i][j][u] += dp[x][y][u - 1];
                            dp[i][j][u] %= MOD;
                        }
                    }
                }
            }
        }
        return dp[u][v][N];
    }
};