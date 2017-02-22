//查找一个缺失的数,0~n缺少一个数，如果加上0~n，则转换为有多个数都出现两次，一个出现一次，
//使用异或解决

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = 0;
        int i=0;
        for(i=0;i<nums.size();i++)
        {
            result^= nums[i];
            result^= i;
        }
        result^=i;
        return result;
    }
};