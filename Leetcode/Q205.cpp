class Solution {
public:
    bool isIsomorphic(string s, string t) {
        //同构首先长度得一致
        //if(s.size()!=t.size()) return false; //题目假设长度一致
        if(s.size()==0 && t.size() == 0) return true;
        map<char,char> dict;
        map<char,char> check; //看s是不是两个映射到一个字符了。记录被映射的字符
        for(int i=0;i<s.size();i++)
        {
            if(dict.find(s[i]) == dict.end()) //看有没有记录对应值，没有就添加
            {
                if(check.find(t[i]) == check.end()) //先前没有被映射过，可以用
                {   
                    dict[s[i]] = t[i];
                    check[t[i]] = s[i];
                }
                else
                    return false;
            }
            else
                if(dict[s[i]] != t[i]) return false;
        }
        return true;
    }
};