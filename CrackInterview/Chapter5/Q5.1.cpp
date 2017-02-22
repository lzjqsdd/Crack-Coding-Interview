//You are given two 32-bit numbers, N and M, and two bit positions, i and j. Write a method to set all bits between i and j in N equal to M (e.g., M becomes a substring of N located at i and starting at j).
//
//EXAMPLE:
//Input: N = 10000000000, M = 10101, i = 2, j = 6
//Output: N = 10001010100
//译文：
//给定两个 32 位的数，N 和 M，还有两个指示位的数，i 和 j。 写程序使得 N 中第 i 位到第 j 位的值与 M 中的相同 (即：M 变成 N 的子串且位于 N 的第 i 位和第 j 位之间)
//例子：
//输入: N = 10000000000, M = 10101, i = 2, j = 6


//Tips
//将数末尾n位置为0，可以通过先右移n位，再左n位。
//取x末尾的n位数。(1<<n)-1)&x

//方案1：
//注意这里i在低位，j在高位
//先保留[0,i)位数据为ret，然后把[0,j]位全部置位0.
//用m << i 位作为掩码，采用或运算 

int update_bits(int n,int m,int i,int j)
{
        int ret = ((1 << i)-1) & n;
        return (n >> (j+1) << (j+1))|(m << i)|ret;
}

//方案2：
//n的中间i-j位为0，其他位为1作为mask，然后和n做位与运算，得到的是n中间段被清0.
//然后用上述结果和(m<<i)做或运算。

//如果一个有符号数的最高为是1，则右移i为，这之间的位都是1，参见Q5.1-tip.cpp