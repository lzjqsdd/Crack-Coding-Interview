//battleships
.........
.xxx...x.
.........
...x.xxx.
.x.x.....
.x.x...x.
.........
["XXX...X",".......","..X.XXX","X.X....","X.X...X"]
["XXX...","...XXX"]
["X..X","...X","...X"]
//从左往右，从上往下遍历，左，上，下必须都是'.'，的个数

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int x = board.size();
        int y = board[0].size();
        int sum=0;
        for(int i=0;i<x;i++)
        for(int j=0;j<y;j++)
        {
            char b,u,l,d;
            if(i-1<0) u = '.'; else u = board[i-1][j];
            if(i+1>=x) d = '.'; else d = board[i+1][j];
            if(j-1<0) l = '.'; else l = board[i][j-1];
            b = board[i][j];
            if(b=='X' && u=='.'&& d=='.' && l=='.') sum++;
        }
        return sum;
    }
};