//给定一个正整数，要求输出这个数的补数(位取反，但是不考虑前导0)
//比如5的二进制表示为 0000 0000 0000 0010。但是不考虑其前导0的情况下的补数，所以只考虑010的flip位101.其他位不变。


class Solution {
public:
    int findComplement(int num) {
        //处理前导0，应该找到一个mask，与前导0对应的位都是0，其余都是1. 通过&运算，前导位依然是0，其后的位保持不变。
        unsigned mask = ~0;
        while(num & mask) mask <<= 1; //不断右移，定位到前导0位置。 如maks = 1111 1110 0000
        return (~num) & (~mask);
    }
};