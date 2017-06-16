#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    public:
        void sortColors(vector<int> &nums)
        {
            if(nums.size() == 0) return;
            int begin=0,current = 0;
            int end = nums.size()-1;

            while(current <= end)
            {
                if(nums[current] == 0){
                    swap(nums[current] ,nums[begin]);
                    current++;begin++;
                }
                else if(nums[current] == 1)
                    current++;
                else if(nums[current] == 2){
                    swap(nums[current],nums[end]);
                    end--;
                }
            }
        }
};

int main()
{
    vector<int> nums={0,0,1,2,0,1,2,2,1,1,2,0,1,0,0,2};
    Solution s;
    s.sortColors(nums);
    for(auto it = nums.begin();it!=nums.end();++it)
        cout << *it << " ";
    cout << endl;
}
