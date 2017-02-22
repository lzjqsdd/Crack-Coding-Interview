//14. Longest Common Prefix
//多个字符串的最长公共前缀

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        if(strs.size() == 1) return strs[0];
        string prefix;
        int i = 0;
        while(true)
        {
            int j=0;
            for(;j<strs.size()-1;++j)
            {
                string s1 = strs[j];
                string s2 = strs[j+1];
                if(i<s1.size() && i<s2.size())
                    if(s1[i]!=s2[j]) break;
            }
            if(j >= strs.size()-1)
                prefix.append(1,strs[0][i]);
        }
        return prefix;
    }
};