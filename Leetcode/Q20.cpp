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