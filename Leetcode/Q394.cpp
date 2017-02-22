//Decode String
//给定一组类似于字符串描述，然后进行解码
//s = "3[a]2[bc]", return "aaabcbc".
//s = "3[a2[c]]", return "accaccacc".
//s = "2[abc]3[cd]ef", return "abcabccdcdcdef".

//使用栈来解析规则
#include <vector>
#include <string>
#include <stack>
using namespace std;


class Solution {
public:
    string decodeString(string s) {
        stack<int> nums;
        stack<char> oper;
        int x = 0;
        string result;
        for(char c:s)
        {
            if(c >= '0' && c<='9')
                x = x*10+c-'0';
            else
            {
                string tmp;
                if(c == '[')
                {
                    nums.push(x);
                    x = 0;
                    oper.push(c);
                }
                else if(c>='a' && c<='z')
                {
                    tmp.append(1,c);                    
                }
                else
                {
                    int n = nums.top(); nums.pop();
                    for(int i=0;i<n;i++)
                        result+=tmp;
                }
        }
    }
};
