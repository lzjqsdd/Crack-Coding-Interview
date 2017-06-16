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


//第二遍AC
//求一组string的最长公共前缀
//如果只有一个字符串，则公共前缀仍为自身
//以第一个字符串为对标，如果其他的同位置字符相同，则往后加

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        if(strs.size() == 1) return strs[0];
        else
        {
            int curpos = 0;
            while(true)
            {
                for(int j=1;j<strs.size();++j)
                {
                    if(curpos < strs[j].size() && curpos < strs[0].size() 
                                   && strs[j][curpos] == strs[0][curpos])
                         continue;
                    else return strs[0].substr(0,curpos); //此时curpos不匹配，匹配的长度为curpos
                }
                curpos++;
            }
        }
        return "";
    }
};