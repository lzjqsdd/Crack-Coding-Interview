//给定一个数n，如果n是偶数，n = n/2,如果n是奇数,n= n+1或者n=n-1.直到n=1.求最小的操作次数。

//位操作。
//(+1) 11->10->1
//(-1) 11->100->10->1

//111
//

//如果最后两位是11的话，最好的操作是+1.
//除此之外-1都是最佳的操作。

//觉得这道题本质还是DP。n的规模不断缩小，其最优值肯定包含更小规模的最优值。
//分为如下情况：
//n为偶数： opt(n) = 1+opt(n+1)
//n为奇数:  opt(n) = 2+min{ opt((n+1)/2), opt((n-1)/2)} 
//为什么是2+min呢？首先如果是奇数，不管+1还是-1都会变为偶数，而偶数的操作是固定的。
//比如opt(5) = min{opt(6),opt(4)} = min{1+opt(3),1+opt(2)} = 1+min{opt(3),opt(2)}
//如果以打表的方式，opt(5)的最有子问题没有opt(6),但是opt(6)最优和opt(3)是等价的。

//opt一般使用打表来记录子问题的解，带来的空间代价比较高。

#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int integerReplacement(int n) {
       if(n == 1) return 0;
       if(opt.count(n) == 0) //如果没有计算过
       {
           if(n & 1) //如果n是奇数
           {
               //opt[n] = 2+min(integerReplacement((n-1)/2), integerReplacement((n+1)/2)); //但是这里出现了n+1.考虑边界情况.n+1可能超出整数范围
               opt[n] = 2+min(integerReplacement(n/2),integerReplacement(n/2+1));
           }
           else
               opt[n] = 1+integerReplacement(n/2);
       }
       return opt[n];
    }
private:
    unordered_map<int,int> opt; 
};