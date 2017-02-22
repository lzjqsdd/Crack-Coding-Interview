//给定数n,输出n位的数中，多少数的每个位均不相同


class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int s;
        if(n == 0) return 0;
        else if(n == 1) return 10;
        else
        {
            s = 10;
            int tmp = 9;
            int x = 10;
            for(int i=2;i<=n;i++){
                tmp*=(--x);
                s+= tmp;
            }
        }
        return s;
    }
};