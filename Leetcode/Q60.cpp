//给定一个序列1-n，现在给定n和k，求1-n的全排列中的第k个元素
//思路：求全排列第k个位置，首先可以通过将全排列以分叉图的方式列出来，可以发现。n>2以上，树的分叉是成组的。比如最后是按找两两分组，k/2
//得到的商可以得到第k/2个分组。该分组为父一级的分叉，而父一级的分叉又是以3为分组。
//分组编号从0开始.通过取

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>num;
        for(int i=1;i<=n;++i) num.push_back(i);
        vector<int> order;
        k--; //编号从0开始
        for(int i=1;i<=n;++i)
        {
            order.push_back(k%i); //余数正是所属的分叉;
            //cout << k%i << endl;
            k = k/i;
        }
        string result="";
        for(int i = order.size()-1;i>=0;--i)
        {
            result+=to_string(num[order[i]]);
            cout << order[i] << endl;
            num.erase(num.begin()+order[i]);
            //cout << num.size() << endl;
        }
        cout << result << endl;
    }
};

int main()
{
    Solution s;
    s.getPermutation(4,14);
}