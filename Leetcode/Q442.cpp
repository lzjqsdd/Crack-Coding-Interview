//和Q448很像，给n个数，取值在1~n,然后找重复出现的数
//依然是占坑，占过了说明重复。
//如果用hash，会浪费空间

class Solution {
public:
    vector<int> findDuplicates(vector<int>& a) {
        vector<int> result;
        for(int i=0;i<a.size();++i)
        {
            int m = abs(a[i]) - 1; //比如4应该放到a[3]，所以标记a[3]
            if(a[m] > 0)
            {
                a[m] = -a[m];
            }
            else
            {
                result.push_back(m+1);
            }
        }
        return result;
    }
};