//题意：给定一组数，调整这组数变成它的下一个更大的排列，如果不存在下一个更大的（已经是最大的排列），这组数必须被排列成
//最小的排列。最大是指这些书排列形成字典序的大小,对于数字来说，字典序和其大小序一样

//思路：因为需要next的数，所以交换应该从最后开始找。如果遍历所有都无法交换，则把数组reverse
//理解错误：应该求的比当前排列大的全排列。假设序列位A1,A2,A3,....Ai,Aj,...An;
//如果在Ai,Aj交换后，则Aj及其之后的元素进行重拍，并按照增序来排列


[1,2,10,11,13]
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for(auto it = nums.rbegin(); it!= nums.rend(); ++it)
        {
            if(it+1!= nums.rend() && *it > *(it+1)) {swap(*it,*(it+1));break;}
        }
        reverse(nums.begin(),it);
    }

    void per(vector<int>&nums,int i) //求i~size-1后面的倒数
    {
        for(int k = nums.size()-1;k >= i+1;--k)
        {
            if(nums[k-1] < nums[k])
            {
                swap(nums[k],nums[k-1]);
                per(nums,k);
            }
        }
    }
};


//求比当前排列的下一个大的全排列。
//全排列的性质 P+Q两部分，固定P，Q作为子问题求全排列



[1,2,4,5,3]
1,2,5,4,3

//[1,3,2]
//[3,1,2] WA
//[2,1,3] EX
//应该从最后元素开始。判断后面的元素有没有比当前元素大的，如果有，取刚好大于的这个数。
//并对交换后的元素到最后的元素进行重排，从小到达重排，因为仅仅要求大于目前序列的下一个排列，所以尽可能小。

//[1,3,5,6,7,3]
//[1 3 2 3 5 4]
//.........i..

void nextPermutation(vector<int>& nums) {
    if(nums.size() < 2) return;
    auto it = nums.rbegin();
    while(it!=num.rend()-1)
    {
        auto j = upper_bound(nums.rbegin(),it+1,*(it+1)); //找到刚好大于该元素的最小的数
        if(j!=(it+1)) //如果当前值找到了可交换的位置
        {
            swap(*j,*(it+1));break;
        }
        ++it;
    }
    sort(nums.rbegin(),it+1,greater<int>());
}