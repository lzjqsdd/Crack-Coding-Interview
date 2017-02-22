//至少连续的三个数，相邻两两的差相同

//长度为n的序列可以有(n-2)(n-1)/2中
#include <vector>
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size() < 3) return 0;
        else
        {
            int len = 2;
            int diff = A[0]-A[1];
            int sum = 0;
            for(int i=1;i<A.size()-1;i++)
            {
                if(A[i]-A[i+1] == diff) len++;
                else
                {
                    //cout << len << endl;
                    diff = A[i]-A[i+1];
                    if(len >= 3 ) sum+=((len-2)*(len-1)/2);
                    len = 2;
                }
            }
            cout <<len << endl;
            if(len >= 3 ) sum+=((len-2)*(len-1)/2);
            return sum;
        }
    }
};