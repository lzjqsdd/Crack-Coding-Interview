#include <iostream>
#include <cmath>
#include <climits>
#include <string>
using namespace std;

//出现TLE:没有把数据置为正的值
//出现WA:-2147483648 -1,已经表示到32位系统的最小的值
//2的倍数可以通过移位来计算
//使用long可以解决问题,但是如果是32为系统的编译器可能就无法通过
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0) return 0;
        if(divisor == 0) return INT_MAX;
        
        
        if(dividend == INT_MAX && divisor == 1)
            return INT_MAX;
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        if(dividend == INT_MIN && divisor == 1)
            return INT_MIN;
        if(dividend == INT_MIN && divisor == INT_MAX)
            return -1;
        if(dividend == divisor) return 1; //主要处理INT_MIN;
        
        
        
        int flag = 1;
        if((dividend < 0 && divisor >0) || dividend > 0 && divisor < 0)
            flag = -1;
        if(divisor == INT_MIN) return 0;
        dividend = abs(dividend); //无论什么时候都置为正的
        divisor = abs(divisor);       
        int result = 0;

        while(dividend >= divisor)
        {
            long tmpDivisor = divisor,k = 0;
            while(dividend >= tmpDivisor)
            {
                dividend -= tmpDivisor;
                result += 1<<k;
                k++;
                if(k == 30) break;
                tmpDivisor <<= 1; //每次把除数变大两倍,步子加快些,但是移位也是有界的
            cout << "dividend:  " << dividend << "      tmpDivisor" << tmpDivisor << endl;
            }
            //剩余部分进行下一轮
        }

        if(flag == -1) result = -result;
        return result;
    }
};

int main(int argc ,char ** argv)
{
    Solution s;
    //cout << s.divide(-2147483648,-1) << endl;
    //cout << s.divide(-1,-2147483648) << endl;
    cout << s.divide(stoi(string(argv[1])),stoi(string(argv[2]))) << endl;
}


//////测试数据
/*
-2147483648
1
-2147483648
-1
2147483647
-1
2147483647
1
-2147483648
2147483647
-2147483648
-2147483648
2147483647
2147483647
-2147483647
-2147483647
2147483647
2
-2147483648
2
*/