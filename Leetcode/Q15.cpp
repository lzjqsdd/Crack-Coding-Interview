//Three sum  = 0
//转换为TwoSum

//TLE
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> result;
        for(int i=0;i<nums.size()-2;++i)
        {
            vector<int>two =  twoSum(nums,i,0-nums[i]);
            if(two.size() == 2)
                result.push_back({nums[i],nums[two[0]],nums[two[1]]});
        }
        return result;
    }
    
    vector<int> twoSum(vector<int>& numbers, int sindex,int target) {
        for(int i=sindex;i<numbers.size();++i)
        {
            int j = binarySearch(numbers,i+1,numbers.size()-1,target-numbers[i]);
            if(j != -1) return {i+1,j+1};
        }
        return {};
    }

    //二分查找logN,但是对N个数查找，总耗时NlogN
    int binarySearch(vector<int>&nums,int s,int t,int target) //返回索引
    {
        //if(s == t && nums[s] == target) return s; 
        if(s > t) return -1;
        else
        {
            int mid = s+(t-s)/2;
            if(target == nums[mid]) return mid;
            else if(target > nums[mid])
                return binarySearch(nums,mid+1,t,target);
            else 
                return binarySearch(nums,s,mid-1,target);
        }
    }
};

//[-1, 0, 1, 2, -1, -4]


//排序，首位指针 n*O(n) = O(n^2)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int> > result;
        for(int i=0;i<nums.size()-2;++i)
        {
            vector<int>two =  twoSum(nums,i+1,0-nums[i]);
            if(two.size() == 2)
                result.push_back({nums[i],nums[two[0]],nums[two[1]]});
        }
        return result;
    }

    vector<int> twoSum(vector<int>& numbers, int sindex,int target) {

        int i  = sindex,j=numbers.size()-1;
        while(i < j)
        {
            int sum = numbers[i]+numbers[j];  
            if(sum == target) return {i,j};
            else if(sum > target) j--;
            else i++;
        }
        return {};
    }
};


//Accept
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3) return {};
        sort(nums.begin(),nums.end());
        vector<vector<int> > result;
        
        for(int k=0;k<nums.size()-2;++k)
        {
            if(k>=1 && nums[k] == nums[k-1]) continue; //去重
            cout <<"k: " << k << endl;
            int i=k+1,j = nums.size()-1,target = 0-nums[k];
            while(i<j)
            {
                int sum = nums[i]+nums[j];
                if(sum < target || (i-1 > k && nums[i-1] == nums[i])) i++;
                else if(sum > target || (j+1 < nums.size() && nums[j] == nums[j+1])) j--;
                else result.push_back({nums[k],nums[i++],nums[j--]});
            }
        }
        return result;
    }
};