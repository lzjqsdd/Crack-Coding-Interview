#include <algorithm>
using namespace std;

/*
看阶乘的这些数中，有多少个5,
第一遍看多少是5的倍数，
第二遍看多少是5^2的倍数，
...

0的阶乘是1，有0个0；
负数没有阶乘
*/



class Solution {
public:
    int trailingZeroes(int n) {
        if(n<=0) return 0;
        int x = 5;
        int result = 0;
        int c = log(n)/log(5);
        for(int i=0;i<c;i++) 
        { result+=(n/x); x*=5; }
        return result;
    }
};