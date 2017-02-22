//4sum
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums) {
        if(nums.size() < 4) return {};
        sort(nums.begin(),nums.end());
        vector<vector<int> > result;
        
        for(int k=0;k<nums.size()-3;++k)
        {
            if(k>=1 && nums[k] == nums[k-1]) continue; //ШЅжи
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