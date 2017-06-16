//给定一个matrix，每行增序，第一列元素增序。但并不代表每列都是增序，可能第一行的元素大于第二行的元素。但可以肯定的是matrix[i][0]之后的元素一定大于该元素
//给定目标target,判断是否存在

//思路:BinarySearch
//考虑如果给定的元素小于第i行的第一个元素，
//先按照第一列元素找到大于target的第一个元素,该行之前所有的行为搜索区域


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0,j=matrix.size()-1;
        int k = 0;
        while(i < j) //i,j区间至少为2
        {
            int mid = i+(j-i)/2;
            if(matrix[mid][0] == target) return true;
            else if(matrix[mid][0] < target) //如果matrix[mid][0] < target ,要找的位置不会包含mid，因为要找的是比target大的数中最小的那个.
                 i = mid+1;
            else j = mid;
        }
        //i即为要搜索的区间的下界
        for(int k=0;k<i;++k)
        {
            if(matrix[k].binary_search(target)) return true;
        }
        return false;
    }
};

//好吧，题目看错，每行第一个大于前一行最后一个，直接把matrix铺开，用二分查找。
//二分查找的mid划分
//假设搜索区间为[i,j],中点为mid,如果 mid > target,要在左半边查找 ，并且左半边区间肯定不包含mid，因为不等于target呀，所以查找区间为[i,mid-1]
//但是如果不满足，说明mid <= target，要在右半边查找，并且mid有可能等于target，所以把mid包含起来.所以查找区间位[mid,j]
