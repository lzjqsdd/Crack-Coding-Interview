#include <iostream>
#include <vector>
#include <limits>
using namespace std;

//Longest Up Subsequence
//[10 9 2 5 3 7 101 18]
int solve(vector<int> &num)
{
    int max_len = 1;
    vector<int>opt(num.size(),1);
    for(int i=0;i<num.size();++i) //每次选择一个序列结尾
    {
        for(int j=0;j<i;++j)
        {
            if(num[i] > num[j])
            {
                opt[i] = max(opt[i],opt[j]+1);
            }
        }
        if(max_len < opt[i]) max_len = opt[i];
    }
    return max_len;
}


int solve_nlogn(vector<int> &num)
{
    if(num.size()==0) return 0;

    vector<int>end(num.size(),0);
    end[0] = num[0];
    int j = 1;
    for(int i=1;i<num.size();++i)
    {
        if(num[i] < end[0]) {end[0] = num[i];}  //如果比最小的还小，就替换最小的，对于形成长序列更有利
        else if(num[i] > end[j-1]) end[j++] = num[i]; //如果比最长序列的还大，就添加新序列，并加上去.
        else //需要替换某个序列最后的大元素为当前较小的值
        {
            auto it = lower_bound(end.begin(),end.begin()+j-1,num[i]);
            *it = num[i];
        }
    }
    return j;
}

int main()
{
    vector<int> test = {10,9,2,5,3,7,101,18,9,10,11};
    cout << solve_nlogn(test) << endl;
}
