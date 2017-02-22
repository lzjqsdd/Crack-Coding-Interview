//Two Sum II - Input array is sorted
//numbers={2, 7, 11, 15}, target=9
//二分搜索 nlogn
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i=0;i<numbers.size();++i)
        {
            int j = binarySearch(numbers,i+1,numbers.size()-1,target-numbers[i]);
            if(j != -1) return {i,j};
        }
    }

    int binarySearch(vector<int>&nums,int s,int t,int target) //返回索引
    {
        if(s == t && nums[s] == target) return s; 
        else if(s > t) return -1;
        else
        {
            int mid = s+(t-s)/2;
            if(target > nums[mid])
                return binarySearch(nums,mid+1,t,target);
            else 
                return binarySearch(nums,s,mid-1,target);
        }
    }
};