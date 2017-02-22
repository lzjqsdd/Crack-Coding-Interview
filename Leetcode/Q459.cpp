//判断一个字符串是否可以通过一个重复的pattern构造
//ababab
class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        int n = str.size();
        int x = n;
        while(x>1)
        {
            if(n%x==0) //先判断能不能分段
            {
                int len = n/x;
                for(int i=0;i<n-len;i+=len)
                {
                    if(str.substr(i,len)!=str.substr(i+len,len))
                        break;
                }
                if(i==n-len) return true;
            }
        }
        return false;
    }
};


"abcabc"
"a"
"aaa"
"abcdabcdabcabcd"