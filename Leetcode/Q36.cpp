  class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++)
        {
            map<char,int> m;
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    if(m.find(board[i][j]) == m.end())
                        m[board[i][j]] = 1;
                    else
                        return false;
                }
                
            }
        }
        
        
        for(int i=0;i<9;i++)
        {
            map<char,int> m;
            for(int j=0;j<9;j++)
            {
                if(board[j][i]!='.')
                {
                    if(m.find(board[j][i]) == m.end())
                        m[board[j][i]] = 1;
                    else
                        return false;
                }
                
            }
        }
        
        int dir[9][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,0},{0,1},{1,-1},{1,0},{1,1}};
        for(int i=1;i<9;i+=3)
        {
            map<char,int> m;
            for(int j=1;j<9;j+=3)
            {
                for(int ii=0;ii<9;ii++)
                    {
                        char c = board[i+dir[ii][0]][j+dir[ii][1]];
                        if(c !='.')
                        {
                            if(m.find(c) == m.end())
                                m[c] = 1;
                            else
                                return false;
                        }   
                    }
            }
        }
        return true;
            
    }
};
