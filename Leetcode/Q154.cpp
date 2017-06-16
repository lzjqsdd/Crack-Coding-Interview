//题意:给定一个旋转后的数组，但是不确定pivot的位置，元素可能重复，求最小的元素
//BinarySearch

//要考虑的是两端相等的情况
//旋转后的增长性如下图所示
//在[i,j]区间内，如果a[mid] > a[j] ,说明在最小值mid之后,且在后半个区间，如果a[mid] < a[j],说明最小值在Mid之前，且在后半个区间
//如果a[mid] == a[j]

/************************

    /|
   / |
  /  |
 /   |
/    |
------------------------
     |     _ _ _
     |    /
     |   /
     |  /
     | /
     |/

*************************/

class Solution {
public:
    int findMin(vector<int> &num) {
        if(num.empty())
            return 0;
        int i=0,j=num.size()-1;
        while(i<j)
        {
            int mid=(i+j)/2;
            if(num[j]<num[mid]){
                i=mid+1;
            }
            else if(num[mid]<num[j]){
                j=mid;
            }
            else{//num[mid]==num[j]
                if(num[i]==num[mid]){//linear complexity
                    i++;
                    j--;
                }
                else
                    j=mid;
            }
        }
        return num[j];
    }
};



/***********************

1 2 3 4 5 6 7 8
5 6 7 8 1 2 3 4

(l)------->------->(r)
分为两端，看mid在哪一段上，当a[mid] < a[r]，说明mid在后半段中，那么最小值要比mid位置还靠前,所以查找l~mid
如果a[mid] > a[r] 说明mid在前半段，但最小值应该还在后半段，所以在mid位置之后，所以查找mid+1 ~ r
如果a[mid] == a[r],[3 3 2 3][2 3 3 3]最小值可能在前半段也可能在后半段，但是可以肯定的是r不是最小值，基于此，
如果a[mid] == a[l],说明l,r,mid三个位置相同，能排除l,r，所以l++,r--;那如果a[mid]!=a[l],而且肯定的是a[l] > a[r],
说明a[l] > a[mid] ,最小值应该在前半段,r=mid

***********************/

public int findMin(int[] nums) {
	 int l = 0, r = nums.length-1;
	 while (l < r) {
		 int mid = (l + r) / 2;
		 if (nums[mid] < nums[r]) {
			 r = mid; //说明最小值在Mid之前
		 } else if (nums[mid] > nums[r]){
			 l = mid + 1; //说明最小值在mid之后
		 } else {  
			 r--;  //nums[mid]=nums[r] no idea, but we can 排除 nums[r];
		 }
	 }
	 return nums[l];
}