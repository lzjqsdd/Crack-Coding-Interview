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

//第二遍：上一次直接使用了int转string，并直接使用reverse来判断是否相同
//如何不使用额外空间呢?
//参考Q7,计算int反过来的数

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int a = x;
        long sum = 0;
        while(x > 0)
        {
            sum  = sum * 10 + x%10;
            x /= 10;
        }
        if(sum == a) return true;
        return false;
    }
};