//题意:给定01矩阵，输出每个元素距离最近的0的距离

//思路：BFS，从四周开始搜索，依次加入队列
//但是在搜索过程中，有些entry的可能被搜索多次，所以可以标记该位置被搜索过，可以直接使用
//结果。考虑到原始matrix的元素0的位置的距离肯定为0。

//每次BFS搜索往队列加入的元素，距离当前位置的距离依次增大，先开始都是距离为1，在加入的元素距离当前元素为2，依次。所以如果碰到0了，可直接跳出。

#include <iostream>
#include <queue>
#include <pair>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> result(m,vector<int>(n));
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                //对每个元素广搜
                if(matrix[i][j] == 0) { result[i][j] = 0;continue;}
                queue<pair<int,int>> q;
                q.push(pair(i,j));
                int min = 0;
                while(!q.emtpy())
                {
                    pair a = q.front(); q.pop();
                    int ii = a.first,jj = a.second;
                    //条件解释：如果当前位置是0，则距离为0,也可以认为计算过了。如果是1，并且该位置result！=0说明计算过，直接加上该位置的值。
                    if(matrix[ii][jj] == 0 || result[ii][jj]!=0) {min+=result[ii][jj]; result[ii][jj] = min; break;}
                    if(ii - 1 >=0 ) q.push(pair(ii-1,jj));
                    if(jj -1 >=0) q.push(pair(ii,jj-1));
                    if(ii+1 < m) q.push(pair(ii+1,jj));
                    if(jj+1 < n) q.push(pair(ii,jj+1));
                }
            }
        return result;
    }
};