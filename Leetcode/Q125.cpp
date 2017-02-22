//判断字符串是不是回文,只考虑字符串中的aplha字母

class Solution {
public:
    bool isPalindrome(string s) {
        istringstream in(s);
        string sv;
        char c;
        while(in >> c)
        {
            if(c>='A' && c<='Z') sv.append(1,c+32);
            else if((c>='a' && c<='z') || (c>='0' && c<='9')) sv.append(1,c);
        }
        if(sv.size() ==0  || sv.size() == 1) return true;
        int i = 0,j = sv.size()-1;
        while(i<j)
        {
            if(sv[i++] != sv[j--]) return false;
        }
        return true;
    }
};