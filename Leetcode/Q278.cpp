//二分查找
// Forward declaration of isBadVersion API.
#include <iostream>
#include <vector>
using namespace std;

bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        return find(1,n);
    }
    int find(int i,int j)
    {
        if(i == j && isBadVersion(i))
        {
            cout << "yes" << endl;
            //result = i;
            return i;
        }
        else
        {
            int mid = i+(j-i)/2;
            if(isBadVersion(mid)) //如果是次品，包含该mid往左查找
            {
                cout << "find(" << i << "," << mid << ")" << endl; 
                return find(i,mid);
            }
            else
            {
                cout << "find(" << mid+1 << "," << j << ")" << endl;
                return find(mid+1,j); //不包含mid往左查找
            }   
        }
    }
    //int result;
};

bool isBadVersion(int version)
{
    vector<int> pro = {1};
    return pro[version-1];
}

int main()
{
    int n = 1;
    Solution s;
    cout << s.firstBadVersion(n) << endl;
}