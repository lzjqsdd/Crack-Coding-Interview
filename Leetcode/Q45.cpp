//Jump Game II
//给定一个序列，每个位置i表示从当前位置可以最多跳的步数，问最少需要多少步可以跳到最后的元素.

//区别于JumpGameII，问是否可以跳到。
//You can assume that you can always reach the last index.假设了总可以跳到。(但并不代表没有0啊)

//[2,3,1,1,4]

//思路1：DP
//opt[i]表示调到当前位置所需的最小的跳数，每次在当前位置以最大方式跳。
//O(n^2)，TLE了

class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> opt(nums.size());
        if(nums.size() <= 1) return 0;
        //for(auto &x:opt) x = INT_MAX;
        for(int i=0;i<opt.size();++i) opt[i] = INT_MAX;
        opt[0] = 0; //第一个位置不用跳
        for(int i = 0;i<nums.size()-1;++i) //到了最后一个位置也不用跳了。
        {
            int k = i + nums[i]; //
            if(k >= nums.size()) k = nums.size()-1; //跳的最远也不能超过最后
            for(int j = i+1;j<=k;++j)
                opt[j] = min(opt[j],opt[i]+1); //从i到k用了1步，加上opt[k]步
        }
        return opt[nums.size() -1];
    }
};

//思路2:Greedy(BFS structure)
//每次以最大的跳数跳。
class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> opt;
        int step = 0;
        int i = 0;
        int curmax = 0;
        while(i < nums.size())
        {
            step++;
            while(i <= curmax) {
                step = max(maxstep,j+nums[j]);
                i++;
            }
            curmax = step;
        }
        return step-1;
    }
};

//[2 3 4 10 2 3 4 5 3 2 1 0]
0->2
------
1->4
2->6
------
3->13
4->6
5->8
6->10
7->12
-----
...

[0]
[2,3,1,1,4]
[1,1,1,1]
[2,3,4,1,2,3,4,5,3,4,6,3,4,6,6,3,1,3,5,1,23]
[9,3,1,3,1,2,3]
[8,1,3,5,54,2,2,1,23,5]