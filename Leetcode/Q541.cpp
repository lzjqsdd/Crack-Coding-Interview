//给定一个字符串，每2k个字符，翻转前k个
//如果剩下的不足k个，全部翻转，如果不足2k个但是大于等于k隔
//翻转前k个

//Input: s = "abcdefg", k = 2
//Output: "bacdfeg"

class Solution {
public:
    string reverseStr(string s, int k) {
        int i = 0;
        for(i = 0;i<s.size();i+=(2*k))
        {
            if(i+2*k < s.size())
                reverse(s.begin()+i,s.begin()+i+k);
            else break;
        }
        if(s.size() - i < k)
            reverse(s.begin()+i,s.end());
        else
            reverse(s.begin()+i,s.begin()+i+k);
        return s;
    }
};