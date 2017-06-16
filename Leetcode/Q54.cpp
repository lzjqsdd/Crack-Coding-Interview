//54. Spiral Matrix
//题意:给定一个矩阵m*n,按照螺旋的方式输出矩阵的元素
//input
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
//output
 [1,2,3,6,9,8,7,4,5].

//思路:螺旋四个走向
//设置四个边界,l,r,u,b分别表示当前方向可以走到的边界.
//初始化:l = 0, r = n-1, u = 0, b = m-1
//初始化位置 i = u,j = l
//分如下四中情况:
//(1) l<r && i=l,j<=r: j++ ,否则u++,且(2)
//(2) u<b && j=r,i<=b: i++ ,否则r--,且(3)
//(3) l<r && i=b,j>=l: j-- ,否则b--,且(4)
//(4) u<b && j=l,i>=u: i-- ,否则l++,且(1)

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size();
    if(m == 0) return {};
    int n = matrix[0].size();
    int l = 0, r = n-1 ,u = 0, b = m-1;
    vector<int> result;
    while(l<=r && u<=b)
    {
        if(u <=b ) //这里是保证这个方向存在(如果宽度或者长度都为0了，该方向没意义f)
        {
            for(int j=l;j<=r;++j) result.push_back(matrix[u][j]); u++;
        }
        if(l <= r)
        {
            for(int i=u;i<=b;++i) result.push_back(matrix[i][r]); r--;
        }
        if(u <= b)
        {
            for(int j=r;j>=l;--j) result.push_back(matrix[b][j]); b--;
        }
        if(l <= r)
        {
            for(int i=b;i>=u;--i) result.push_back(matrix[i][l]); l++;
        }

    }
    return result;

    }
};