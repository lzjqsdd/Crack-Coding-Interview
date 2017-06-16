//Remove K digits
//题意：给定一个字符串，表示一个数字。从其中移除k位，使得结果的数字最小。

//思路：为了让结果尽可能小，那么靠前的大的应该被移除，让高位的数字尽可能小，同时保证被移除的位数为k
//Greedy,添加哨兵‘9’，遍历字符串，
//在每一步中，如果当前字符小于结果中的字符，则删除结果最后一位，则删除最后一位，然后继续判断当前字符和最后一位。
//当前字符还是比较小，持续删除结果最后一位，直到不满足条件或者删除的位数已经达到了k,结束。

class Solution {
public:
    string removeKdigits(string num, int k) {
        string result = "0";
        for(auto x:num)
        {
            while(k && result.back() > x)
            {
                result.pop_back();
                k--;
            }
            result+=x;
        }
        while(k--) result.pop_back(); //如果后面没有更小的再来替换前面的，则说明后面的字母是递增的，从后往前删出直到k为0.
        int i = 0;
        while(i < result.size() && result[i] == '0') i++; //移除前导0
        return result.substr(i).size() > 0 ? result.substr(i) : "0" ;
        //return result;
    }
};