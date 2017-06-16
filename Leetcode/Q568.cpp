//568. Maximum Vacation Days （Lock）
//题意：旅行n个城市，每个城市有不同的度假天数，如何旅行能够获得最大的度假天数

//限制条件：只允许旅行n个城市，初始在city0
//城市之间的连接由n*n的矩阵表示城市之间是否由航班。
//总共只有k周来旅行，每天最多只能乘坐一次航班，而且只能在每周的周一乘坐（切换城市）
//给定矩阵 days[i][j]表示jack在城市i在第j周能待的天数


//思路：DP
//定义opt[day_i][city_j]表示第i周待在城市j能够获得的最大的vacuation天数
//则 opt[i][j] = max{opt[i-1][k] if city[k][j] == 1 for all cities k};

//可以待在原城市，其实flight[i][i] = 1;
//AC
class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int n = flights.size(); if(n == 0) return 0;
        int k = days[0].size(); //m表示可以k周
        vector<vector<int>>opt (k,vector<int>(n,-1));
        for(int i = 0;i<n;++i) flights[i][i] = 1;
        //初始化第1周
        for(int i = 0;i<n;++i) opt[0][i] = flights[0][i] * days[i][0];
        for(int day = 1;day<k;++day)
        {
            for(int i = 0;i<n;++i)
            {
                for(int j = 0;j<n;++j) //城市j到城市i
                {
                     if(flights[j][i] == 1 && opt[day-1][j] >= 0) //>=0表示前一天城市j是可以达到的
                        opt[day][i] = max(opt[day][i],opt[day-1][j]+days[i][day]);
                }
            }
        }

        int res = 0;
        for(int i = 0;i<n;++i) res = max(res,opt[k-1][i]);
        return res;
    }
};

//卡壳原因：代码未保证前一天的城市是否曾经可达
[[0,1,1],[1,0,1],[1,1,0]]
[[1,3,1],[6,0,3],[3,3,3]] 12
[[0,0,0],[0,0,0],[0,0,0]]
[[1,1,1],[7,7,7],[7,7,7]] 3
[[0,1,1],[1,0,1],[1,1,0]]
[[1,1,1],[7,7,7],[7,7,7]] 21

[[0,1,0],[0,0,0],[0,0,0]]
[[0,0,7],[2,0,0],[7,7,7]]


























const int N = 200;
int dp[N][N];

class Solution {
public:
    int maxVacationDays(vector<vector<int>>& a, vector<vector<int>>& b) {
        int n = a.size(), m = b[0].size();
        for (int i = 0; i < n; ++i) a[i][i] = 1;
        for (int i = 0; i < n; ++i) {
            dp[m - 1][i] = b[i][m - 1];
        }
        for (int k = m - 2; k >= 0; --k) {
            for (int i = 0; i < n; ++i) {
                int& cur = dp[k][i];
                cur = 0;
                for (int j = 0; j < n; ++j) {
                    if (a[i][j]) {
                        cur = max(cur, dp[k + 1][j]);
                    }
                }
                cur += b[i][k];
            }
        }
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            if (a[0][i]) {
                ret = max(ret, dp[0][i]);
            }
        }
        return ret;
        
    }
};


