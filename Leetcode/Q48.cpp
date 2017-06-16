//题目意思：顺时针旋转一个图像
//思路：先按照左上-右下对角线对称变换，然后水平方向对称变换

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //对角线翻折
        for(int i=0;i<n;++i)
            for(int j=0;j<i;++j)
            {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }

        for(int i=0;i<n/2;++i)
            for(int j=0;j<n;++j)
            {
                int tmp = matrix[j][i];
                matrix[j][i] = matrix[j][n-1-i];
                matrix[j][n-1-i] = tmp;
            }
    }
};