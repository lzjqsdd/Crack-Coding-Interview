//题意：给定一个包含0,1的矩阵，1-1表示朋友，求朋友圈（直接或者间接的朋友）的数量
//思路:Union-Find,BFS


//BFS，该方法描述的矩阵元素之间的关系（题意不是这样的）
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int count = 0;
        int m = M.size(); if(m == 0) return 0;
        int n = M[0].size(); if(n==0) return 0;
        vector<vector<int>> v(m,vector<int>(n,0));
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j)
            {
                if(M[i][j] == 0) continue;
                if(!v[i][j])
                {
                    count++;
                    queue<pair<int,int>> q;
                    q.push(make_pair(i,j));
                    v[i][j] = 1;//切记先被访问再入队列
                    while(!q.empty())
                    {
                        pair<int,int> pos = q.front();
                        q.pop();
                        int ii = pos.first,jj = pos.second;
                        if(ii-1>=0 && M[ii-1][jj] == 1 && !v[ii-1][jj]) {q.push(make_pair(ii-1,jj)); v[ii-1][jj] = 1;}
                        if(jj-1>=0 && M[ii][jj-1] == 1 && !v[ii][jj-1]) {q.push(make_pair(ii,jj-1)); v[ii][jj-1] = 1;}
                        if(ii+1<m && M[ii+1][jj] == 1 && !v[ii+1][jj]) {q.push(make_pair(ii+1,jj)); v[ii+1][jj] = 1;}
                        if(jj+1<n && M[ii][jj+1] == 1 && !v[ii][jj+1]) {q.push(make_pair(ii,jj+1)); v[ii][jj+1] = 1;}
                    }
                }
            }

        return count;
    }
};

//智障。。。M[i][j]表示的是第i个人和第j个人是朋友
//M的输入必然是一个对称阵。

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {

            int m = M.size(); //m表示人数
            if(m == 0) return 0;
            vector<int>id(m);
            for(int i=0;i<m;++i) id[i] = i; //初始每个人各自为一个集合
            for(int i=0;i<m;++i)
            {
                int flag = 0;
                for(int j=0;j<i;++j)
                {
                    if(M[i][j] == 1) //union
                    {
                        flag = 1;
                        int minidd = min(id[i],id[j]);
                        int maxidd = max(id[i],id[j]);
                        for(int k=0;k<=i;++k)
                        {
                            if(id[k] == maxidd) id[k] = minidd;
                        }
                    }
                }
            }
            int count = 0;
            for(int i=0;i<id.size();++i) if(id[i] == i) count++; //统计
        return count;
    }
};


[[1,1,0,0,0,0,0,1,0,0,0,0,0,0,0]
,[1,1,0,0,0,0,0,0,0,0,0,0,0,0,0]
,[0,0,1,0,0,0,0,0,0,0,0,0,0,0,0]
,[0,0,0,1,0,1,1,0,0,0,0,0,0,0,0]
,[0,0,0,0,1,0,0,0,0,1,1,0,0,0,0]
,[0,0,0,1,0,1,0,0,0,0,1,0,0,0,0]
,[0,0,0,1,0,0,1,0,1,0,0,0,0,1,0]
,[1,0,0,0,0,0,0,1,1,0,0,0,0,0,0]
,[0,0,0,0,0,0,1,1,1,0,0,0,0,1,0]
,[0,0,0,0,1,0,0,0,0,1,0,1,0,0,1]
,[0,0,0,0,1,1,0,0,0,0,1,1,0,0,0]
,[0,0,0,0,0,0,0,0,0,1,1,1,0,0,0]
,[0,0,0,0,0,0,0,0,0,0,0,0,1,0,0]
,[0,0,0,0,0,0,1,0,1,0,0,0,0,1,0]
,[0,0,0,0,0,0,0,0,0,1,0,0,0,0,1]]


class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {

            int m = M.size(); //m表示人数
            if(m == 0) return 0;
            vector<int>id(m);
            int count = m;
            for(int i=0;i<m;++i) id[i] = i; //初始每个人各自为一个集合
            for(int i=0;i<m;++i)
            {
                int flag = 0;
                for(int j=0;j<i;++j)
                {
                    if(M[i][j] == 1)
                    {
                        if(id[i] != id[j]) count--; //改动这里，不同说明要合并，则集合数减1
                        flag = 1;
                        int minidd = min(id[i],id[j]);
                        int maxidd = max(id[i],id[j]);
                        for(int k=0;k<=i;++k)
                        {
                            if(id[k] == maxidd) id[k] = minidd;
                        }
                    }
                }
            }
        return count;
    }
};