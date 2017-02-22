// Assign Cookies
// 每个孩子对cookier的大小有最低的需求g_i,每个饼干大小为s_j
// 对还在和饼干分别排序，
//每次尽可能给需求小的孩子，使得满足的孩子最多。因为如果连需求小的孩子都不能满足，更不可能满足需求大的孩子。
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int k = g.size() < s.size() ? g.size():s.size();
        int i=0,j=0;
        while(i<k&&j<k)
        {
            if(s[k] >= g[k])
            {
                i++;j++;
            }
            else
            {
                j++;
            }
        }
        return i; //最后一个被满足的孩子为i-1，总个数为i
    }
};