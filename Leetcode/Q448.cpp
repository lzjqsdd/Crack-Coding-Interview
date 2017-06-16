//题目意思：给定一组数0～n，其中有的数出现两次，有的出现一次，问0～n中哪些数缺失
//思路：物归原主，各自占坑。
//每次判断该数和所在位置匹配，继续往下走
//否则，取出该数，将该位置标记为-1，不断调换使得与所在位置相同.


//或者用本身所在的值的正负来标记该位置是否被占用.

#include<iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> a = {4,3,2,7,8,2,3,1};  
    vector<int> result;
    for(int i=0;i<a.size();++i)
    {
        int m = abs(a[i]) - 1; //比如4应该放到a[3]，所以标记a[3]
        a[m] = a[m] > 0 ? -a[m]:a[m]; //小于0表示位置被占
    }

    for(int i=0;i<a.size();++i)
        if(a[i] < 0) result.push_back(i+1);
    return result;
}