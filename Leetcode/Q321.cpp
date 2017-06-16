321. Create Maximum Number
//题意：给定两个数组nums1,nums2,元素取值为0~9，要求从其中选择k个数组成一个数字，使得这个数最大

//思路：考虑结果数字最大，意味着最终结果来自于两个数组中较大的一些数。并且要求结果中来自各自的数组的元素的相对位置
//不变。可以从前往后遍历两个数组，把靠前的较小的数字移除（移除|nums1|+|nums2|-k个）。剩下的按照从大打到的顺序组合起来即可。

//为什么这么考虑。如果考虑每次选择较大的一个，那么可能nums[1]某个位置较小，而其后元素都很大，但是因为从前往后选择，导致结果过多
//的选择Nums[2]中的元素。

//让组合的结果尽可能大，也就意味着靠前的小的元素应该被移除。留下大的让按照相对顺序组合。



class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        k = nums1.size() + nums2.size() - k ; //转换为删除k个较小的元素使得结果最大。
        auto it1 = nums1.begin();
        auto it2 = nums2.begin();
        while(it1!=nums.end() && it2!=nums.end())
        {

        }
    }
};