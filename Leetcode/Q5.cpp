//题意：查找字符串s中最长的回文子串
//思路：以当前元素为中心，向左右两边扩展。
//比如 babad ,分别从i=0到i=4，考虑每个元素作为回文中心（仅对于奇数串）。对于偶数串，则会出现a[i] = a[i+1].

//仍然从小问题开始，如果是一个元素，则这个元素为回文串。
//如果两个元素，如果不同，则分别都可以作为回文串
//如果三个元素，aba,则a，b，a分别都可以作为回文中心。对于aab，aa也可以作为回文中心。
//我们从如下例子分析: bacccad，对于b,a因为没有相邻的相同的，所以都只能作为奇数子串的中心，对于c，cc相邻，则cc可以作为回文串中心，如果还有
//相同的，如ccc,那么ccc仍然可以作为回文串中心。

//所以本题关键是定位好回文子串的起始位置。开始l,r都位于cur位置，如果r始终有相同的相邻元素，则r++;
//复杂度O(n^2)
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() <= 1) return s;
        int maxlen = 1,res_l = 0;
        for(int i = 0;i<s.size();++i)
        {
            int l = i,r = i; //初始回文串大小只有1，l = r = i;
            while(r+1 < string.size() && s[r] == s[r+1]) r++; 
            //这里作为优化，没必要每个元素都考虑。如果有多个重复，则后续考虑直接调到重复元素之后；
            //因为右界停止，说明a[r] != a[r+1],而l+1 ~ r之间都是重复元素，说明中间的元素都和a[r+1]不同，以这些元素
            //为中心组成的回文串不会超过r-l+1长度的，所以不需要再考虑。
            i = r;
            while(l - 1 >= 0 && r+1 < string.size() && s[l-1] == s[r+1])
            {
                l--;r++;
            }
            int len = r - l + 1;
            if(maxlen < len) {maxlen = len; res_l = l; }
        }
        return s.substr(res_l,maxlen);
    }
};

//注意另外一个问题，最长回文子序列（和最长回文子串),子序列可以不用连续，采用DP的方式实现。
//opt[i][j]表示i到j之间最长的回文长度,return Opt[0][n-1]

//本问题求最长的回文子串，以当前元素为中心向两侧扩展
//baaab，baab,bab，从某个元素出发，连续相同的总可以构成回文子串,


class Solution {
public:
    string longestPalindrome(string s) {
        int maxlen = 0;
        int res_l = 0;
        for(int i = 0;i<s.size();++i)
        {
            int l = i,r = i;
            while(r+1 < s.size() && s[r] == s[r+1]) r++;

            i = r; //优化：下次直接跳过中间重复元素
            while(l-1 >= 0 && r+1 < s.size() && s[l-1] == s[r+1])
            {
                l--;r++;
            }
            int len = r - l + 1;
            if(maxlen < len)
            {
                maxlen = len;
                res_l = l;
            }
        }
        return s.substr(res_l,maxlen);
    }
};