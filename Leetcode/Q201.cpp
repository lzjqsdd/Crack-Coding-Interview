//题意：给定一个闭区间，给出该区间内所有数的位与
//最简单的想法就是从m到n做AND运算。
//看似很简单，但是如果给定一个区间0~2147483647，显然按单个数与会TLE。
//所以还需要考虑与运算的特点。

//m = 01010100
//n = 01011010
//只要m<n,则m,n之间必然有奇数和偶数，所以末尾的与运算一定是0
//
//结果 01000000

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int result=0;
        while(m != n)
        {
            m >>= 1;
            n >>= 1; //只要小于，最后一位的所有数的AND操作都是0；
            //result <<= 1;
            result++;
        }
        return m << result;
    }
};