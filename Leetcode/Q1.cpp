/*Two Sum*/
/*二分查找*/
#include <iostream>
#include <cstdlib>
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef struct Pair 
{
	int index;
	int value;
}Pair;

bool cmp(const Pair& a,const Pair& b)
{
	return a.value < b.value;
}

int find(vector<Pair>nums,int s,int t,int target)
{
	if(s<=t)
	{
		int mid = (s+t)/2;
		if(target == nums[mid].value) return mid;
		else if(nums[mid].value>target) return find(nums,s,mid-1,target);
		else if(nums[mid].value<target) return find(nums,mid+1,t,target);

	}
	else
		return -1;
}

vector<int> twoSum(vector<int>& nums,int target)
{
	vector<Pair> p;
	vector<int> result;

	Pair ptmp;
	for(int i=0;i<nums.size();i++)
	{
		ptmp.value = nums[i];
		ptmp.index = i;
		p.push_back(ptmp);
	}

	sort(p.begin(),p.end(),cmp);
	for(int i=0;i<p.size();i++)
	{
		int tg = target-p[i].value;
		int r = find(p,i+1,p.size(),tg);
//		cout<<r<<endl;
		if(r!=-1)
		{
			int index1 = p[i].index+1;
			int index2 = p[r].index+1;
			vector<int> result;
			if(index1<index2){result.push_back(index1);result.push_back(index2);}
			else {result.push_back(index2);result.push_back(index1);}
			return result;
		}
	}
}

int main()
{
	vector<int> nums;
	nums.push_back(0);
	nums.push_back(4);
	nums.push_back(3);
	nums.push_back(0);


	vector<int> result = twoSum(nums,0);
	cout<<result[0]<<" "<<result[1]<<endl;

	return 0;

}




//第二遍：
//如果是有序，可以使用TwoPointers
//AC
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		int i = 0;
		for(int i = 0;i<nums.size();++i)
		{
			auto it = find(nums.begin()+i+1,nums.end(),target-nums[i]);
			if(it != nums.end()) return {i,it-nums.begin()};
		}
    }
};