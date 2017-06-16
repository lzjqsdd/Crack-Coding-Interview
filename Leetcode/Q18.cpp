//4sum.

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size() < 4) return {};

        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        for(int i=0;i<nums.size()-3;++i)
        {
            if(i-1 >= 0 && nums[i-1] == nums[i]) continue; //去重
            for(int j = i+1;j<nums.size()-2;++j)
            {
                if(j-1 >= i+1 && nums[j-1] == nums[j]) continue; //去重的思路是为了防止子问题有相同的前缀,但不影响相同元素可以组合.
                //if(nums[i]+nums[j] > target) continue; //这句话是错误的,因为继续求和还可能是sum更小.比如[1,-2,-5,-4,-3,3,3,5],-11
                int p = j+1,q = nums.size() - 1;
                int t =  target - nums[i] - nums[j];
                while(p < q)
                {
                    cout << p << "," << q << endl;
                    if(nums[p] + nums[q] > t)
                    {
                        while(nums[q] == nums[q-1]) q--;
                        q--;
                    }
                    else if(nums[p] + nums[q] < t)
                    {
                        while(nums[p] == nums[p+1]) p++;
                        p++;
                    }
                    else
                    {
                        result.push_back({nums[i],nums[j],nums[p],nums[q]});
                        while(nums[q] == nums[q-1]) q--;
                        while(nums[p] == nums[p+1]) p++;
                        p++;q--;
                    }
                }
            }
        }
        return result;
    }
};

int main()
{
    vector<int> test = {1,2,3,4,5,6,3,1,2,23,5,5};
    Solution s;
    s.fourSum(test,0);
    return 0;
}



//第二遍
//去重思路和3sum相同
//同样先排序，然后固定i,j,通过two-pointer确定k,m
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size() < 4) return {};
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        for(int i = 0;i<nums.size()-3;++i)
        {
            //第一位去重
            if(i-1 >= 0 && nums[i-1] == nums[i]) continue;
            for(int j = i+1;j<nums.size()-2;++j)
            {
                //第二位去重
                if(j-1 >= i+1 && nums[j-1] == nums[j]) continue;

                int sum = target - nums[i] - nums[j];
                int p = j+1;
                int q = nums.size()-1;
                while(p < q)
                {
                    if(nums[p] + nums[q] == sum)
                    {
                        result.push_back({nums[i],nums[j],nums[p],nums[q]});
                        //while循环用来去重
                        while(nums[q] == nums[q-1]) q--; //选择了q之后，q之前和nums[q]相同的不要
                        while(nums[p] == nums[p+1]) p++; //同理
                        q--;p++; //
                    }
                    else if(nums[p] + nums[q] > sum)
                    {
                        while(nums[q] == nums[q-1]) q--; //相同的不满足的都去掉
                        q--;
                    }
                    else
                    {
                        while(nums[p] == nums[p+1]) p++;
                        p++;
                    }
                }
            }
        }
        return result;
    }
};