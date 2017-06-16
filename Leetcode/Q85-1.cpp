#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
  public:
    int maximalRectangle(vector<string> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int opt[m][n][6]; //[2]中，0表示横向的面积，1表示纵向的,维护矩形长和宽

        opt[0][0][0] = matrix[0][0];
        opt[0][0][1] = matrix[0][0];
        opt[0][0][2] = matrix[0][0];
        opt[0][0][3] = matrix[0][0];
        opt[0][0][4] = matrix[0][0];
        opt[0][0][5] = matrix[0][0];

        int maxa = 0;
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j)
            {
                if (matrix[i][j] == '0')
                    opt[i][j][0] = opt[i][j][1] = opt[i][j][2] = opt[i][j][3] = opt[i][j][4] = opt[i][j][5] = 0;
                else
                {
                    opt[i][j][0] = opt[i][j][1] = opt[i][j][2] = opt[i][j][3] = opt[i][j][4] = opt[i][j][5] = 1;
                    if(i - 1 >= 0)  opt[i][j][1] = opt[i - 1][j][1] + 1;
                    if(j - 1 >= 0)  opt[i][j][0] = opt[i][j - 1][0] + 1;
                    
                    if (i - 1 >= 0 && matrix[i - 1][j] == '1')
                    {
                            opt[i][j][2] = min(opt[i][j][0], opt[i - 1][j][2]);
                            opt[i][j][3] = opt[i - 1][j][3] + 1;
                    }
                    else
                    {
                            opt[i][j][2] = opt[i][j][0];
                            opt[i][j][3] = opt[i][j][1];
                    }
                    if (j - 1 >= 0 && matrix[i][j - 1] == '1')
                    {
                            opt[i][j][4] = opt[i][j-1][4] + 1;
                            opt[i][j][5] = min(opt[i][j][1],opt[i][j-1][5]);
                    }
                    else
                    {
                            opt[i][j][4] = opt[i][j][0];
                            opt[i][j][5] = opt[i][j][1];
                    }
                    maxa = max(maxa,opt[i][j][0]);
                    maxa = max(maxa,opt[i][j][1]);
                    maxa = max(maxa,opt[i][j][2]*opt[i][j][3]);
                    maxa = max(maxa,opt[i][j][4]*opt[i][j][5]);
                }
                for(int k=0;k<6;++k) cout << opt[i][j][k] << " ";
                cout << endl;
            }
            cout << endl;
        }
        return maxa;
    }
};

int main()
{
    vector<string> test = {"11010","01110","11110","11111"};
    Solution s;
    s.maximalRectangle(test);
}