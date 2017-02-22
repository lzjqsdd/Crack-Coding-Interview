#include <iostream>
#include <string>
#include <cmath>
using namespace std;

//可以直接把整数转换为string,比较反转后的是不是和反转前的相同.
// 注意输入的为int,所以要考虑负数

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        string s = to_string(x);
        string stmp = s;
        reverse(s.begin(),s.end());
        if(stmp == s)
            return true;
        return false;
    }
};