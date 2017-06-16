//Next Greater Element III
//题意:给定一个32-bit数字n,给出最小的数x,且x和n的数字一样(只是位置不同),比如123,231,321.x是大于n的最小值.
//如果不存在则返回-1


#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

//我怎么想起来了全排列那个题.给定一个全排列,找出仅大于给定排列的一个排列
//好吧,果然用上了
class Solution {
public:
    int nextGreaterElement(int n) {
        //转string
        string nums="";
        int ntmp = n;
        while(n)
        {
            nums+=to_string(n%10);
            n/=10;
        }
        //转换完的string为逆序
        reverse(nums.begin(),nums.end());
       
        auto it = nums.rbegin();
        while(it!=nums.rend()-1)
        {
            auto j = upper_bound(nums.rbegin(),it+1,*(it+1)); //找到刚好大于该元素的最小的数
            if(j!=(it+1)) //如果当前值找到了可交换的位置
            {
                swap(*j,*(it+1));break;
            }
            ++it;
        }
        if(it+1 != nums.rend())
            sort(nums.rbegin(),it+1,greater<char>());


        long result = 0;
        for(auto it = nums.begin();it!=nums.end();++it)
            result  = result*10 + *it-'0';
        if(result ==  ntmp || result > INT_MAX) return -1;
        return result;   
    }
};


/*
12
12345
4313541
34151
4123
34153451
4321
1
21
12
11
12345
*/


//1999999999


int main()
{
    int n = 1999999999;
    Solution s;
    cout << s.nextGreaterElement(n) << endl;
    return 0;
}