//Reverse Integer
//这个问题的坑在于：反过来之后可能出现越界，如果溢出则返回0

class Solution {
public:
    int reverse(int x) {
        long long  sum = 0;
        long long flag = 1;
        if(x < 0){ x = -x; flag = -1;}
        while(x>0) //注意这里的>0,另外x = -2147483648,-x依然是,有符号的最小值x,-x表示一样。
        {
            sum = sum*10 + x%10;
            if(sum > INT_MAX) return 0;
            x /= 10;
        }
        if(flag < 0) sum = -sum;
        return sum;
    }
};