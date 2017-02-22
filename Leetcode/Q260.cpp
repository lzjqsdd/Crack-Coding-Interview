//数组中有两个数只出现一次，其他出现两次。

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int AandB = 0;
        for(int x:nums)
            AandB ^= x;
        for(int b:nums)
        {
            int a = AandB; //3^5 
            x = a^x; //if x== 3 x = 3^3^5 = 5;
            a = a^x; //a = 3^5^5 = 3;
            if(a^x = AandB) return {a,x};
        }
    }
};

http://www.wengweitao.com/lintcode-single-number-i-ii-iii-luo-dan-de-shu.html