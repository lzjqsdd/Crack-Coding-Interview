class Solution {
public:
//此方案问题：nums.end()-k,则后面k个数并未进行查找
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(k >= nums.size()) k = nums.size()-1; //座标的差值最多为size-1
        for(auto it=nums.begin();it!=nums.end()-k;++it)
        {
            if(find(it+1,it+k+1,*it) != (it+k+1)) return true;
        }
        return false;
    }

    //AC
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
       map<int,int>dict;
       for(int i=0;i<nums.size();++i)
       {
            if(dict.find(nums[i]) == dict.end()) //如果没记录
                dict[nums[i]]=i;
            else
            {
                if(i - dict[nums[i]] <= k) return true;
                else dict[nums[i]] = i;
            }
       }
       return false;
    }
};