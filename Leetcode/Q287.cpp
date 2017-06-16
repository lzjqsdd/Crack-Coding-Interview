//题意：在n+1个元素中查找相同的元素,元素取值范围为1-n，并且假定只有一个重复元素
//根据容屉原理，说明每个元素至少都出现了一次，多出来那一次就是重复的元素

//但是重复元素不止一次啊！！，比如[2,2,2,2]
//可转化为求链表中环开始的位置的问题 同142

//元素取值位1~n,如果不含重复元素，从1~n+1开始每个下标对应一个。
//[x,1,2,3,4,5,6]
//[2,1,2,3,4,5,6]
//那如果出现重复元素，则在访问过程中肯定会再次访问到该元素，说明访问顺序中存在环。访问方式：元素值作为下次访问的下标
#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int>& nums) {
    //return accumulate(nums.begin(),nums.end(),0) - (nums.size() *  (nums.size()-1))/2;
    //起始访问的位置下标为0
    int slow = nums[0];
    int fast = nums[nums[0]];
    while(slow != fast)
    {
        fast = nums[nums[fast]];
        slow = nums[slow];
    }
    slow = 0;
    while(slow != fast)
    {
        fast = nums[fast];
        slow = nums[slow];
    }
    return slow;
}

int main()
{
    vector<int> test= {1,2,3,4,2,5};
    cout <<findDuplicate(test) << endl;
}

        int slow = nums[0];
		int fast = nums[nums[0]];
		while (slow != fast)
		{
			slow = nums[slow];
			fast = nums[nums[fast]];
		}

		fast = 0;
		while (fast != slow)
		{
			fast = nums[fast];
			slow = nums[slow];
		}
		return slow;