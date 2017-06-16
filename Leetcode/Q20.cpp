#include <iostream>
#include <string>
#include <stack>
using namespace std;


bool isVaild(string s)
{
    if(s.size() == 0) return 0;
    stack<char> sk;
    map<char,char> dict = {{'(',')'},{'[',']'},{'{','}'},{'#','#'};
    sk.push_back('#');
    for(int i=0;i<s.size();++i)
    {
        char c = sk.top();
        if(dict[c] == s[i]) sk.pop();
        else sk.push_back(s[i]);
    }
    if(sk.size() == 1) return true;
    return false;
}


//第二遍
//判断给定的字符串的括号匹配是否是合法的,包括(),{},[]
//遇到匹配问题考虑栈
class Solution {
public:
    bool isValid(string s) {
        if(s.size() == 0) return true;
        stack<char> sk;
        sk.push('#'); //加入哨兵方便处理
        map<char,char> dict = {{'(',')'},{'[',']'},{'{','}'},{'#','#'}};
        for(int i = 0;i<s.size();++i)
        {
            char c = sk.top();
            if(dict[c] == s[i]) sk.pop();
            else sk.push(s[i]);
        }
        if(sk.size() == 1) return true;
        return false;
    }
};