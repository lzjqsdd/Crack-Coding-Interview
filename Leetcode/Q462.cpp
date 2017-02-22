//Minimum Moves to Equal Array Elements 
//TotalS = TotalS - (size-i-1)*(nums[i]-nums[i-1]) + (i-1)*(nums[i]-nums[i-1]);
//       = TotalS+(nums[i]-nums[i-1])*(2*i-1-size);

// Long 类型，先排序，然后按照前后两段计算，滑动窗口
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        if(nums.size() <= 1) return 0;
        long totalS = 0;
        sort(nums.begin(),nums.end());
        for(int x:nums)
            totalS+=(x-nums[0]);
        cout << "init" << totalS << endl;
        long minr = LONG_MAX;
        for(int i=1;2*i<=nums.size();i++)
        {
            totalS+=(nums[i]-nums[i-1])*(2*i-nums.size());
            cout << totalS << endl;
            if(totalS < minr)  minr = totalS;
        }
        return minr;
    }
};