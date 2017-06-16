//题意：给定数组，查找所有出现n/3次的元素
//unordered_map记录次数
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>result;
        unordered_map<int,int> dict;
        for(auto it=nums.begin();it!=nums.end();++it)
        {
            if(dict.find(*it) != dict.end()) dict[*it]=0;
            else dict[*it]++;

            if(dict[*it] > nums.size()/3) result.push_back(*it);
        }
        return result;
    }
};