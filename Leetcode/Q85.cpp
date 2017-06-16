//给定matrix，包含0或者1，求只由1能形成的最大的矩形的面积。
//
1 0 1 0 0 1 0 1 1 1 1 1 1 1 1 1 0 0 1 0

    opt(i, j) 作为矩形的右下角，如果该角可以加入形成矩形，则加入。判断条件由对角、左侧、上侧来确定。 opt[i][j] =

        1 0 1 0 0 2 0 2 2 2 3 2

    (1, 1)(0, 0)(1, 1)(0, 0)(0, 0)(1, 2)(0, 0)(1, 2)(2, 1)(3, 1)(1, 3)(2, 1)(3, 3)(4, 2)(5, 2)(1, 4)(0, 0)(0, 0)(1, 3)(0, 0)

    //构建矩形可以理解为右下角包围更小的矩形
    //如图
    // 1 1 1 | 1
    // 1 1 1 | 1
    // —— —— —
    // 1 1 1   1

    class Solution
{
  public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int opt[m][n][4]; //[2]中，0表示横向的面积，1表示纵向的,维护矩形长和宽

        opt[0][0][0] = matrix[0][0];
        opt[0][0][1] = matrix[0][0];
        opt[0][0][2] = matrix[0][0];
        opt[0][0][3] = matrix[0][0];

        int maxa = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                if (matrix[i][j] == '0')
                {
                    opt[i][j][0] = opt[i][j][1] = opt[i][j][2] = opt[i][j][2] = 0;
                }
                else
                {
                    if (j - 1 >= 0) //横向可以组成x*1大小的矩形
                        opt[i][j][0] = opt[i][j - 1][0] + 1;
                    else
                        opt[i][j][0] = 1;
                    if (i - 1 >= 0) //纵向可以组成1*x大小的矩形
                        opt[i][j][1] = opt[i - 1][j][1] + 1;
                    else
                        opt[i][j][1] = 1;

                    opt[i][j][2] = opt[i][j][3] = 1;
                    if (i - 1 >= 0 && j - 1 >= 0) //尝试包围矩形
                    {
                        opt[i][j][2] = min(opt[i - 1][j - 1][2] + 1, opt[i][j][0]);
                        opt[i][j][3] = min(opt[i - 1][j - 1][3] + 1, opt[i][j][1]);
                    }
                    maxa = max(max(max(opt[i][j][0], opt[i][j][1]), opt[i][j][2] * opt[i][j][3]), maxa);
                }
            }
        return maxa;
    }
};

[ "10100", "10111", "11111", "10010" ]
["10100", "10011", "11111", "10010"]
["10101", "11111", "11011", "10011"]
["10011"]
["0"]
["1"]
[]
["1110001", "1101101", "1010101", "0000000", "1111001", "1011001"]

    0 1 1 0 1 1 1 0 1 0 0 1 1 1 0 //这行第一个0，并不是矩形3*3中的
    1 1 1 1 0 1 1 1 1 1 0 0 0 0 0

class Solution
{
  public:
    int maximalRectangle(vector<vector<char>> &matrix)
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


["111","111","111"]
[ "10100", "10111", "11111", "10010" ]
["10100", "10011", "11111", "10010"]
["10101", "11111", "11011", "10011"]
["10011"]
["0"]
["1"]
[]
["1110001", "1101101", "1010101", "0000000", "1111001", "1011001"]
["11100011110","11100011110","10101011110","11111011110","11100010110","11100111110","11101011110"]