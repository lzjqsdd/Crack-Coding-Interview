//O(mn) space，记录每个为0的位置，最后把这些行列设置为0
//O(m+n) space,记录为0的行，记录为0的列
#include <iostream>
#include <set>
#include <vector>
using namespace std;
class Solution {
    public:
        void setZeroes(vector<vector<int>>& matrix) {
            set<int> row;
            set<int> col;
            int m = matrix.size();
            int n = matrix[0].size();
            for(int i=0;i<m;++i)
                for(int j=0;j<n;++j)
                    if(matrix[i][j] == 0)
                    {
                        row.insert(i);
                        col.insert(j);
                    }

            for(auto it = row.begin();it!=row.end();++it)
                for(int j=0;j<n;++j)
                    matrix[*it][j] = 0;
            for(auto it = col.begin();it!=col.end();++it)
                for(int i=0;i<n;++i)
                    matrix[i][*it] = 0;
        }
};

int main()
{
    return 0;
}
