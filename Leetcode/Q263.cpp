#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//质因子只有2,3,5的，一个和数可以分解为质数相乘，不断用2,3,5进行分解，如果最后剩余的数不是1，说明有其他质因子

class Solution {
public:
    bool isUgly(int num) {
        if(num<=0) return false;
        while(num%2 == 0) num/=2;
        while(num%3 == 0) num/=3;
        while(num%5 == 0) num/=5;
        if(num == 1) return true;
        return false;
    }
};