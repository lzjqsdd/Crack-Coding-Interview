//题意：求直方图中最大的矩形面积
//http://www.cnblogs.com/felixfang/p/3676193.html
//波峰图

//可以遍历每个柱子用O(n^2)
//但是观察波峰图，很容易发现，如果给定一个上升序列，那么这些矩形都超不过波峰，较低的总可以
//为了更好的有波峰的性质，在序列末尾加入哨兵形成最低的尾。

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
  public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> index; //栈里存index，为了方便计算宽
        height.push_back(0);
        int left = 0, right = 0;
        for (int i = 0; i < height.size(); ++i)
        {
            while (!st.empty() && height[st.top()] > height[i]) //出栈
            {
                int tmp = st.top();
                st.pop();
                leftarea = (st.empty() ? tmp + 1 : tmp - st.top()) * height[tmp]; //以tmp为高度，tmp所在柱以及向左延伸出来的矩形面积
                rightarea = (i - tmp - 1) * height[tmp];                          //以tmp为高度，向右边延伸出来的矩形面积
                if ((leftarea + rightarea) > MAX)
                    MAX = (leftarea + rightarea);
            }
            st.push(i);
        }
    };

    class Solution
    {
      public:
        int largestRectangleArea(vector<int> &height)
        {

            int ret = 0;
            height.push_back(0);
            vector<int> index;

            for (int i = 0; i < height.size(); i++)
            {
                while (index.size() > 0 && height[index.back()] >= height[i])
                {
                    int h = height[index.back()];
                    index.pop_back();

                    int sidx = index.size() > 0 ? index.back() : -1;
                    if (h * (i - sidx - 1) > ret)
                        ret = h * (i - sidx - 1);
                }
                index.push_back(i);
            }

            return ret;
        }
    };

    class Solution
    {
      public:
        int largestRectangleArea(vector<int> &height)
        {
            stack<int> index;
            height.push_back(0); //设置哨兵
            int maxa = 0;
            for(int i=0;i<height.size();++i)
            {
                //每次判断当前要入栈的元素是否大于栈顶，如果大于栈顶，继续压栈，否则出栈计算面积
                while(!index.empty() && height[index.top()] >= height[i])
                {
                    int h = height[index.top()];
                    index.pop();

                    int l = index.empty() ? -1:index.top();
                    if(h*(i - l -1 ) > maxa)  //面积位当前柱到i（不包含i)所构成的矩形，高度位当前柱的高度（一个上升区间，矩形取决于低的柱子）
                        maxa = h*(i-l-1);
                }
                //把当前index的入栈
                stack.push(i);
            }
            return maxa;
        }
    };