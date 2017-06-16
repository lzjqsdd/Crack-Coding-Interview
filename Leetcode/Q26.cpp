//Easy题，给定一个sort好的数组，移除重复元素，返回新的数组的长度。
//但是引用传递进来的，题目也要求删除这些元素
//其实就是返回不重复元素的长度

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int count = 1;
        auto it = nums.begin()+1;
        while(it!= nums.end())
        {
            if(*it == *(it-1))
                it = nums.erase(it);
            else
            {
                it++;
                count++;
            }
        }
        return count;
    }
};