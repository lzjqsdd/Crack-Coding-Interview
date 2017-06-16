//计算连续子数组和，是否等于目标

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int m = nums.size();
        if(m == 0) return 0;
	int result = 0 ;
	vector<int> presum;
	presum.push_back(0);
	for(int i = 0;i<nums.size();++i)
	    presum.push_back(presum.back()+nums[i]);

	for(int i = 0;i<nums.size();++i)
	    for(int j = i;j<nums.size();++j)
		if(presum[j+1] - presum[i] == k) result++;
        return result;
    }
};



//使用map可以存储多个相同的值。避免多次+1;
class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        map<int, int> mp;
        mp[0]++;
        int s = 0, ans = 0;
        for (int i : a) {
            s += i;
            ans += mp[s - k];
            mp[s]++;
        }
        return ans;
    }
};
