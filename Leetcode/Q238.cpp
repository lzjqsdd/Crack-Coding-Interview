//数组元素的除了i位置之外元素的乘积
//O(N)time,constant space
//分为左右两部分的乘积
//-------------------------------------------
// 1             2      3       4
// 1            1*2     1*2*3   1*2*3*4
// 1*2*3*4      2*3*4   3*4     4
//-------------------------------------------
// p(2) = l(1)*r(3)
//-------------------------------------------
//[1 2 3 4]
//[24 12 8 6]
// nums左侧累积，tmp右侧累积
// tmp[i] = tmp[size-1-(i+1)] * nums[i-1];

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.size() == 1) return {nums[0]};
        vector<int> tmp; //存储右侧的累积
        int s = 1;
        for(auto rit=nums.rbegin();rit!=nums.rend();++rit)
        {
            s*= (*rit);
            cout << s << endl;
            tmp.push_back(s);
        }
        for(int i=1;i<nums.size();++i)
        {   
            nums[i] = nums[i]*nums[i-1];
            cout << nums[i] << endl;
        }

        reverse(tmp.begin(),tmp.end());
        tmp[0] = tmp[1];
        for(int i=1;i<tmp.size()-1;i++)
            tmp[i] = nums[i-1]*tmp[i+1];
        tmp[tmp.size()-1] = nums[nums.size()-2]; //这句位置很重要
        return tmp;
    }
};