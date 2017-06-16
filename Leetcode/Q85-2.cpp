#include <iostream>
#include <vector>
#include <string>

using namespace std;

//转换为计算最大的直方图面积
//每行作为基底，但是如果出现元素为0，则纵向高度为0.纵向高度应该为当前元素为1且连续向上都为1的个数。

//预先计算每个元素作为基底时的直方图的高度h[i][j],然后分层计算最大的直方图面积。

class Solution
{
  public:
    int maximalRectangle(vector<string> &matrix)
    {
        int m = matrix.size();
        if (m == 0)
            return 0;
        int n = matrix[0].size();
        if (n == 0)
            return 0;
        vector<vector<int>>h(m,vector<int>(n)); //h可以考虑空间优化
        int maxa = 0;
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j)
            {
                if(matrix[i][j] == '0')
                    h[i][j] = 0;
                else
                {
                    if(i-1>=0)
                        h[i][j] = h[i-1][j]+1; 
                    else
                        h[i][j] = 1;
                }
            }
            maxa = max(maxa,largestRectangleArea(h[i]));
        }
        return maxa;
    }
    int largestRectangleArea(vector<int> &height)
    {
        stack<int> index;
        height.push_back(0); //设置哨兵
        int maxa = 0;
        for (int i = 0; i < height.size(); ++i)
        {
            //每次判断当前要入栈的元素是否大于栈顶，如果大于栈顶，继续压栈，否则出栈计算面积
            while (!index.empty() && height[index.top()] >= height[i])
            {
                int h = height[index.top()];
                index.pop();

                int l = index.empty() ? -1 : index.top();
                if (h * (i - l - 1) > maxa) //面积位当前柱到i（不包含i)所构成的矩形，高度位当前柱的高度（一个上升区间，矩形取决于低的柱子）
                    maxa = h * (i - l - 1);
            }
            //把当前index的入栈
            stack.push(i);
        }
        return maxa;
    }
};

int main()
{
    vector<string> test = {"11010", "01110", "11110", "11111"};
    Solution s;
    s.maximalRectangle(test);
}