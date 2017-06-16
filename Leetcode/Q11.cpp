//给一个柱型图，每个柱子长度非零。求最多可以盛多少水？每个柱子都是一个容器，如果两个柱子之间的柱子比较低，还可以在顶部盛水
//找出两个柱子i,j,这两个柱子组成的容器的容量最大
//波峰图

//TwoPointers
//从两端开始构建容器，（木桶原理）
//如果i之后的柱子更低，是得不到更多的容量。所以下面代码两个while循环重新确定新的容器边界


#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  public:
    int maxArea(vector<int> &height)
    {
        int maxv = 0;
        int i = 0;
        int j = height.size() - 1;
        while (i < j)
        {
            int h = min(height[i], height[j]);
            maxv = max(maxv, (j - i) * h);
            while (height[i] <= h && i < j)
                ++i;
            while (height[j] <= h && i < j)
                --j;
        }
        return maxv;
    }
};