#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//按照26进制来处理 
//给定的是正整数,所以从1开始
//打表,数组表示为A-Z 对应0~25,下标为对应的数字.比如array[3]为Z
//给定的数都减一,从0开始表示26进制更直观
// (n-1)/26+1; n = (n-1)/26 why:因为即使是26也不能进位,然而进制确实26进制,所以为了刚好商刚好为26导致的余数
// 为0,通过-1可以做到避免进位,但是余数就少了1,所以计算余数要再加1.
// 余数应该是1~26,
class Solution {
public:
    string convertToTitle(int n) {
        string table = ".ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string result;
        while(n!=0)
        {
            int x = (n-1)%26+1;
            result.append(1,table[x]);
            n = (n-1)/26;
        }
        reverse(result.begin(),result.end());
        cout << result << endl;
        return result;
    }
};