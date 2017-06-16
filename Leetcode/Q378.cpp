//n*n matrix,�����������������ҵ�k��С��
/*
---------------
|1   5    9
|   -----------
|10 | 11   13
|   |    -------
|12 | 13 |  15
|   |    |
*/


matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int s = 2*n-1;
        int i = 0;
        while(k > s) { k-=s;s-=2;i++;} //并不是如上图所示外层都小于内层
        vector<int> target;
        target.push_back(matrix[i][i]);
        int j = i+1;
        while(j<n)
        {
            target.push_back(matrix[j++][i]);
            target.push_back(matrix[i][j++]);
        }
        sort(target.begin(),target.end());
        return target[k-1];
    }
};

[[1,5,9],[10,11,13],[12,13,15]]
1
[[1,5,9],[10,11,13],[12,13,15]]
2
[[1,5,9],[10,11,13],[12,13,15]]
3
[[1,5,9],[10,11,13],[12,13,15]]
4
[[1,5,9],[10,11,13],[12,13,15]]
5
[[1,5,9],[10,11,13],[12,13,15]]
6
[[1,5,9],[10,11,13],[12,13,15]]
7
[[1,5,9],[10,11,13],[12,13,15]]
8
[[1,5,9],[10,11,13],[12,13,15]]
9