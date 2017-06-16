//给定一个网格，填充1，0 1代表岛屿，0代表水，找出有几个岛屿。岛屿是被水围起来的连通区域。
//思路：维护无向图的联通性问题，使用Union_Find + BFS

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int numIslands(vector<string>& grid) {
        int num = 0;
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();
        vector<vector<int>> visit(m,vector<int>(n,0));
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j)
            {
                if(grid[i][j] == '1' && !visit[i][j]) //0不考虑,如果是1且没被访问过
                {
                    num++;
                    queue<pair<int,int>> q;
                    q.push(make_pair(i,j));
                    visited[i][j] = 1;
                    while(!q.empty())
                    {
                        pair<int,int> pos = q.front();
                        q.pop();
                        int ii = pos.first,jj = pos.second;
                        //cout << ii << "," << jj << endl;
                        //visit[ii][jj] = 1; //错在了这里，应该先标记才入队列而不是出队列才标记。
                        if(ii-1>=0 && grid[ii-1][jj] == '1' && !visit[ii-1][jj]) {q.push(make_pair(ii-1,jj)); visit[ii-1][jj] = 1;}
                        if(ii+1<m && grid[ii+1][jj] == '1' && !visit[ii+1][jj]) {q.push(make_pair(ii+1,jj)); visit[ii+1][jj] = 1;}
                        if(jj-1 >=0 && grid[ii][jj-1] == '1' && !visit[ii][jj-1]) q.push(make_pair(ii,jj-1)); visit[ii][jj-1] = 1;}
                        if(jj+1<n && grid[ii][jj+1] == '1' && !visit[ii][jj+1]) q.push(make_pair(ii,jj+1)); visit[ii][jj+1] = 1;}
                    }
                }
            }

        return num;
    }
};


int main()
{
    vector<string> test = {
        "11111011111111101011",
        "01111111111110111110",
        "10111001101111111111",
        "11110111111111111111",
        "10011111111111111111",
        "10111111011101110111",
        "01111111111101101111",
        "11111111111101111011",
        "11111111110111111111",
        "11111111111111111111",
        "01111111011111111111",
        "11111111111111111111",
        "11111111111111111111",
        "11111011111110111111",
        "10111110111011110111"};

        Solution s;
        s.numIslands(test);
}

/*
["11111011111111101011",
 "01111111111110111110",
 "10111001101111111111",
 "11110111111111111111",
 "10011111111111111111",
 "10111111011101110111",
 "01111111111101101111",
 "11111111111101111011",
 "11111111110111111111",
 "11111111111111111111",
 "01111111011111111111",
 "11111111111111111111",
 "11111111111111111111",
 "11111011111110111111",
 "10111110111011110111",
 
 
 "11111111111101111110",
 "11111111111110111100",
 "11111111111111111111",
 "11111111111111111111",
 "11111111111111111111"]
 */