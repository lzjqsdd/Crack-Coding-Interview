#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//DP思想，转换为斐波那契数列

class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;
        int f1 = 1;
        int f2 = 2;
        for(int i=3;i<=n;i++)
        {
            int f3 = f1+f2;
            f1 = f2;
            f2 = f3;
        }
        return f2;
    }
};