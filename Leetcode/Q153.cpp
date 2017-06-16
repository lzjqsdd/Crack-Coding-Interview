//给定一个数组，该数组之前是有序的，经过某个pivot旋转得到的。
//求最小的数,数组中没有重复的元素

//0 1 2 3 4 5 6 7 变为4 5 6 7 0 1 2
//思路：直接找到转折点
//7,6,5,4,3,2,1,0会出现么？
//三种趋势，直上直下，直上，直下

/*------------------
 /\     /    \
/  \   /      \
--------------------*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int i = 0;
        while(i < nums.size()-1 && nums[i] < nums[i+1]) ++i; //因为下降趋势停止有两种情况，直下和转折
        if(i == nums.size()-1) return nums.front(); //keep asend
        else
        {
            if(nums[i+1] < nums[i+2]) return nums[i+1];
            else return nums.back();
        }
    }
};


//经典二分搜索问题
//只要存在pivot,那么首元素肯定大于尾元素
 int findMin(vector<int> &num) {
        int start=0,end=num.size()-1;
        
        while (start<end) {
            if (num[start]<num[end])
                return num[start];
            
            int mid = (start+end)/2;
            
            if (num[mid]>=num[start]) {
                start = mid+1;
            } else {
                end = mid;
            }
        }
        
        return num[start];
    }

