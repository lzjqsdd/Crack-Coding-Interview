//题意：Game of Life
//给定m*n矩阵，每个格子0或者1表示die或者live，每个各自的状态由邻域8个格子决定，并且这个状态的更新必须同时
//要求：in-place

//如果live->die，因为要求in-place，可以先用-1表示该格子即将die,
//对于1变为-1, 但是使用 -1 %2 仍为1同样表示更新前的状态
//对于0变为2, 但是使用2%2仍为0,同样表示更新前状态

//在c++ 中 -1%2= -1

i-1,j-1   i-1,j   i-1,j+1
i,j-1     i,j     i,j+1
i+1,j-1   i+1,j   i+1,j+1

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j)
            {
                int sum = 0;
                if(i>0)
                {
                    sum+= abs(board[i-1][j]%2);
                    if(j>0) sum+= abs(board[i-1][j-1]%2);
                    if(j<n-1) sum+= abs(board[i-1][j+1]%2);
                }
                if(i<m-1)
                {
                    sum+= abs(board[i+1][j]%2);
                    if(j>0) sum+= abs(board[i+1][j-1]%2);
                    if(j<n-1) sum+= abs(board[i+1][j+1]%2);
                }
                if(j>0) sum+= abs(board[i][j-1]%2);
                if(j<n-1) sum+= abs(board[i][j+1]%2);

                //cout << sum << " ";
                if(abs(board[i][j]%2) == 1) //当前为活着
                {
                    if(sum>3 || sum<2) board[i][j] = -1;
                }
                else
                {
                    if(sum == 3) board[i][j] = 2;
                }
            }
            //cout << endl;
        }

         for(int i=0;i<m;++i)
            for(int j=0;j<n;++j)
                if(board[i][j] == -1) board[i][j] = 0;
                else if(board[i][j] == 2) board[i][j] =1;
    }
};