//给定一个棋盘格，'O'和'X'组成,找出'O'被X包围的区域。然后把该区域的'O'替换成'X';
// X X X X
// X O O X
// X X O X
// X O X X

//思路：BFS,UnionFind


//为什么选择并查集：如果应用场景只关注联通性，而不关注连通的路径问题，并查集可以处理，不需要记录其路径。否则使用比如 DFS 或者 BFS
//并查集几个关键步骤：
// make_set
// find_set
// union_set
// 为什么使用树的结构？而不是给每个节点分配组号。
// 结构包括：data,rank,parent. 


class Solution {
public:
    int numIslands(vector<string>& grid) {
        int num = 0;
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();
        vector<vector<int>> visit(m,vector<int>(n,0));
        vector<vector<int>> flip; //记录要被翻转的区域，如果该区域不需要翻转，则
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j)
            {
                if(grid[i][j] == 'O' && !visit[i][j]) //0不考虑,如果是1且没被访问过
                {
                    vector<pair<int,int>> mfilp; int flag = 0; //标记该集合是否最后需要加入反转的集合中
                    queue<pair<int,int>> q;
                    q.push(make_pair(i,j));
                    visited[i][j] = 1;
                    while(!q.empty())
                    {
                        pair<int,int> pos = q.front();
                        q.pop();
                        int ii = pos.first,jj = pos.second
                        if(ii == 0 || ii == m-1 || jj == 0 || jj == n-1) //说明该集合有边界的部分,并不封闭
                            flag = 1;
                        if(ii-1>=0 && grid[ii-1][jj] == 'O' && !visit[ii-1][jj]) {q.push(make_pair(ii-1,jj)); visit[ii-1][jj] = 1;}
                        if(ii+1<m && grid[ii+1][jj] == 'O' && !visit[ii+1][jj]) {q.push(make_pair(ii+1,jj)); visit[ii+1][jj] = 1;}
                        if(jj-1 >=0 && grid[ii][jj-1] == 'O' && !visit[ii][jj-1]) q.push(make_pair(ii,jj-1)); visit[ii][jj-1] = 1;}
                        if(jj+1<n && grid[ii][jj+1] == 'O' && !visit[ii][jj+1]) q.push(make_pair(ii,jj+1)); visit[ii][jj+1] = 1;}
                    }
                    if(!flag) flip.push_back(mfilp);   
                }
            }
        for(auto i:flip)
            for(auto j:i)
                grid[j.first][j.second] = 'x';
    }
};