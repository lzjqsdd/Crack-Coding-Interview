#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
using namespace std;

/*
注意事项：
1 两个非等长的有序序列
2 log(m+n)复杂度
*/

//关键思路：（1）Find-Cut，找出两个数组的分割点。求两个非等长数组的中位数，那么必然存在两个数组的分割位C1和C2，使得合并后C1,C2左侧的均小于右侧的，C1+C2占一半数量。
// （2）如何把奇数偶数统一起来，不然很多边界条件 - 填充虚拟位置。因为想把分割点也作为一个位置，这样方便处理。不然对于偶数来说，分割点不存在。
// 通过二分法查找cut的位置
//由于C1,C2和固定，所以查找其中一个即可。复杂度O(log min(n1,n2)).以较小的数组为例，二分查找C2的位置。

//A1: [# 1 # 2 # 3 # 4 # 5 #]    (N1 = 5, N1_positions = 11)
//A2: [# 1 # 1 # 1 # 1 #]     (N2 = 4, N2_positions = 9)

// A1 = [L1 C1 R1]
// A2 = [L2 C2 R2]
//则对于划分C1,C2,最终应该保证L1 < R1 && L1 < R2 && L2 < R2 && L2 < R1，即合并后的分割点，两个左侧均小于两个右侧
//对于L1 < R1,L2 < R2 是已经保证的，所以要保证的是L1 < R2以及L2 < R1
//那么对于分割C2，如果L1 > R2 说明 L1中有过多的large number，所以应该把分割点C1左移(对应的C2右移)。也意味着分割点位置查找范围缩减到前一半。

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int N1 = nums1.size();
    int N2 = nums2.size();
    if (N1 < N2)
        return findMedianSortedArrays(nums2, nums1); // Make sure A2 is the shorter one.

    if (N2 == 0)
        return ((double)nums1[(N1 - 1) / 2] + (double)nums1[N1 / 2]) / 2; // If A2 is empty

    int lo = 0, hi = N2 * 2; //0～N2*2
    while (lo <= hi)
    {
        int mid2 = (lo + hi) / 2;  // Try Cut 2
        int mid1 = N1 + N2 - mid2; // Calculate Cut 1 accordingly

        double L1 = (mid1 == 0) ? INT_MIN : nums1[(mid1 - 1) / 2]; // Get L1, R1, L2, R2 respectively
        double L2 = (mid2 == 0) ? INT_MIN : nums2[(mid2 - 1) / 2];
        double R1 = (mid1 == N1 * 2) ? INT_MAX : nums1[(mid1) / 2];
        double R2 = (mid2 == N2 * 2) ? INT_MAX : nums2[(mid2) / 2];

        if (L1 > R2)
            lo = mid2 + 1; // A1's lower half is too big; need to move C1 left (C2 right)
        else if (L2 > R1)
            hi = mid2 - 1; // A2's lower half too big; need to move C2 left.
        else
            return (max(L1, L2) + min(R1, R2)) / 2; // Otherwise, that's the right cut.
    }
    return -1;
}

int main()
{
    vector<int> A = {1, 2, 3, 4};
    vector<int> B = {2, 4, 5};
    cout << findMedianSortedArrays(A, B) << endl;
}



//myself

class Solution {
public:
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size();
    int n2 = nums2.size();

    //nums1为较大的，nums2为较小的
    if(n1 < n2) return findMedianSortedArrays(nums2,nums1);
    if(n2 == 0) {
        double res = (nums1[(n1-1)/2] + nums1[n1/2]) / 2.0;
        return res;
    }
    
    //以A2为基准查找分割点C2，从0~2*N2.那么对应的C1的分割点为N1+N2-C2.
    //可以观察到由分割点C2得到L2，如果分割点C2为填充位置，则L2紧邻C2,如果分割点为数字，则L2相差一个位置。
    //总结起来 L2 = Nums2[(C2-1)/2],R2 = Nums2[C2/2]
    int low = 0,high = n2*2; //初始查找范围
    while(low <= high)
    {
        int mid2 = (low + high) / 2;
        int mid1 = n1 + n2 - mid2;

        double l1 = (mid1 == 0) ? INT_MIN : nums1[(mid1-1)/2];
        double l2 = (mid2 == 0) ? INT_MIN : nums2[(mid2-1)/2];
        double r1 = (mid1 == n1*2) ? INT_MAX : nums1[mid1/2];
        double r2 = (mid2 == n2*2) ? INT_MAX : nums2[mid2/2];

        if(l1 > r2)
            low = mid2 + 1;
        else if(l2 > r1)
            high = mid2 - 1;
        else
            return (max(l1,l2) + min(r1,r2))/2.0;
    }
    return -1;
}
};


//第二遍
//求二分法求分割点C1,C2
//填充后两个序列总和总为偶数(2*N1+1 + 2*N2+1 = 2(N1+N2+1))
//其中点m1,m2之和为N1+N2

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int N1 = nums1.size();
        int N2 = nums2.size();
        if(N1 < N2) return findMedianSortedArrays(nums2,nums1);

        if(N2 == 0) return ((nums1[(N1-1)/2] + nums1[N1/2]))/2.0;

        //1#2#3#4#5# 范围为[0,n2*2]
        //填充位置与实际位置的映射关系  (i-1)/2
        int l = 0,r = N2*2; //在填充过的数组上查找
        while(l<=r)
        {
            int mid2 = (l+r)/2;
            int mid1 = N1+N2-mid2;

            double l1 = (mid1 == 0) ? INT_MIN: nums1[(mid1-1)/2];
            double l2 = (mid2 == 0) ? INT_MIN: nums2[(mid2-1)/2];
            double r1 = (mid1 == N1*2) ? INT_MAX:nums1[mid1/2];
            double r2 = (mid2 == N2*2) ? INT_MAX:nums2[mid2/2];

            if(l1 > r2)
                l = mid2 + 1; //mid2右移,则在右侧查找
            else if(l2 > r1)
                r = mid2 - 1;
            else
                return (max(l1,l2) + min(r1,r2))/2.0;
        }

    }
};