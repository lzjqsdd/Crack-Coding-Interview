//比赛游戏，每个选手每次只能选择序列的首/尾元素,A[i,j]的第i个或第j个，Player1先选择，问Player1会不会赢。（以Player1取得最大的利益为目标)
//思路: DP/Maxmin

//dp(i,j) 表示序列A[i]~A[j]，先手能够获得的最大的分数（两个玩家的分数之差），Player1作为先手可以选择A[i]或者A[j]
//则留下的序列为A[i+1]~A[j] 或者 A[i]~A[j-1],对于留下来的序列，Player2为后手。为了让Player尽可能多得分，所以对于Player2应该尽可能小。
//先手的用正数表示，后手的用负数表示。最小化Player2的分数等价于 最大化负的数。

//所以:dp(i,j) = max(-dp(i+1,j)+ nums[i], -dp(i,j-1) + nums[j] )


class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        return dp(nums,0,n-1) >= 0;
    }
    int dp(vector<int>&nums,int i,int j)
    {
        if(i == j) return nums[i];
        else return max(nums[i] - dp(nums,i+1,j), nums[j] - dp(nums,i,j-1));
    }
};