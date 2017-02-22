//Super Pow
//参考快速幂的求法

#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int ans = 1;
        for(auto rit = b.rbegin();rit!=b.rend();++rit)
        {
            int tmp = powermod(a,*rit,1337);
            ans = (ans * tmp) % 1337;
            a = powermod(a,10,1227);
        }
        return ans;
    }

    int powermod(int a,int b,int c) //每次求一个进位的a
    {
        int ans = 1;
        a = a%c;
        while(b>0)
        {
            if(b%2 == 1) ans = (ans * a) % c;
            b = b/2;
            a = (a * a) % c;
        }
        return ans;
    }
};