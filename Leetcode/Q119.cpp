#include <iostream>
#include <vector>
using namespace std;
//返回杨辉三角形第n排，空间为O(n) ，可以重复利用上一层的数据，递推处理

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0) return {1};
        else if(rowIndex == 1) return {1,1};
        else //从第三层开始
        {
            vector<int> r = {1,1};
            for(int k=2;k<=rowIndex;k++) //递推rowindex次
            {
                int tmp = r[0];
                for(int i=1;i<k;i++)
                {
                    int s = tmp+r[i];
                    tmp = r[i];
                    r[i] = s;
                }
                r.push_back(1);
            }
            return r;
        }
    }
};