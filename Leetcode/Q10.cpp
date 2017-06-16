//10. Regular Expression Matching
//题意：正则表达式匹配，
//'.'能够匹配任意的单一的字符
//'*'能够匹配0个或者多个前置字符


'.' Matches any single character.
'*' Matches zero or more of the preceding element.

//必须完全匹配，而不是局部匹配
The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
//注意：这里的 a * 表示 a 可以重复 0 次或者多次，不是 a 和 * 分开的。

/*
1, If p.charAt(j) == s.charAt(i) :  dp[i][j] = dp[i-1][j-1]; //完全匹配
2, If p.charAt(j) == '.' : dp[i][j] = dp[i-1][j-1]; //只要是'.',任意字符都可以匹配。
3, If p.charAt(j) == '*':  //可能是a*,也可能是.*
   here are two sub conditions:
               1   if p.charAt(j-1) != s.charAt(i) : dp[i][j] = dp[i][j-2]  //in this case, a* only counts as empty
               2   if p.charAt(j-1) == s.charAt(i) or p.charAt(j-1) == '.':
                              dp[i][j] = dp[i-1][j]    //in this case, a* counts as multiple a 
                           or dp[i][j] = dp[i][j-1]   // in this case, a* counts as single a
                           or dp[i][j] = dp[i][j-2]   // in this case, a* counts as empty
Here is the solution
*/

public boolean isMatch(String s, String p) {

    if (s == null || p == null) {
        return false;
    }
    boolean[][] dp = new boolean[s.length()+1][p.length()+1];
    dp[0][0] = true;
    for (int i = 0; i < p.length(); i++) {
        if (p.charAt(i) == '*' && dp[0][i-1]) {
            dp[0][i+1] = true;
        }
    }
    for (int i = 0 ; i < s.length(); i++) {
        for (int j = 0; j < p.length(); j++) {
            if (p.charAt(j) == '.') {
                dp[i+1][j+1] = dp[i][j];
            }
            if (p.charAt(j) == s.charAt(i)) {
                dp[i+1][j+1] = dp[i][j];
            }
            if (p.charAt(j) == '*') {
                if (p.charAt(j-1) != s.charAt(i) && p.charAt(j-1) != '.') {
                    dp[i+1][j+1] = dp[i+1][j-1];
                } else {
                    dp[i+1][j+1] = (dp[i+1][j] || dp[i][j+1] || dp[i+1][j-1]);
                }
            }
        }
    }
    return dp[s.length()][p.length()];
}

//第二遍
class Solution {
public:
    bool isMatch(string s, string p) {
        if(s=="" && p=="") return true;

        vector<vector<bool>> mat(s.size()+1,vector<bool>(p.size()+1,false));
        int i = 0, j = 0;

        //状态初始化.空串和(a*)匹配为true
        mat[0][0] = true;
        for(int j = 0;j<p.size();++j)
            if(p[j] == '*' && mat[0][j-1])
                mat[0][j+1] = true;

        for(int i = 0;i<s.size();++i)
        {
            for(int j=0;j<p.size();++j)
            {
                if(p[j] == '*') //出现"*"的时候j至少为1
                {
                    if(p[j-1] != s[i] && p[j-1] != '.')
                        mat[i+1][j+1] = mat[i+1][j-1]; //把*匹配成空的
                    else //p[j-1] == '.' 或者 匹配字符
                    {
                        mat[i+1][j+1] = 
                            (mat[i+1][j] ||  //表示匹配一个a
                            mat[i][j+1] ||  //表示匹配多个a
                            mat[i+1][j-1]);  //表示匹配0个a
                    }
                }
                else if(p[j] == '.' || p[j] == s[i]) //错在直接else了,而没有else if
                    mat[i+1][j+1] = mat[i][j];
            }
        }
        return mat[s.size()][p.size()];

    }
};