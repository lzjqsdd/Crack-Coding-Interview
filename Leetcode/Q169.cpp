//题意：给定一个大小为n的数组，求出这个数组中的出现次数超过n/2的数
//思路(1)： 由于出现超过n/2，所以要求的值至少有两个相同的相邻，当前其他数也可能相邻
//最极端情况，每隔一个插入一个数，如 1 2 1 3 1 4 1 1。
//思路(2): hash-table，统计个数
//思路(3): sort,中点肯定为答案
//思路(4): 随机化方法，每次随机选择一个数，然后遍历所有数统计是否和该数相同
//思路(5): Divide&Conquer,如果递归两侧的结果相同，则为答案。

//摩尔投票法
//摩尔投票法的基本思想很简单，
//在每一轮投票过程中，从数组中找出一对不同的元素，将其从数组中删除。这样不断的删除直到无法再进行投票，如果数组为空，则没有任何元素出现的次数超过该数组长度的一半。如果只存在一种元素，那么这个元素则可能为目标元素。
//http://mabusyao.iteye.com/blog/2223195
public class Solution {
    public int majorityElement(int[] num) {

        int major=num[0], count = 1;
        for(int i=1; i<num.length;i++){
            if(count==0){
                count++;
                major=num[i];
            }else if(major==num[i]){
                count++;
            }else count--;
            
        }
        return major;
    }
}

//推广到n/3,可以指定两个major,顶多有两个数的个数>n/3

// bit
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = 0, n = nums.size();
        for (int i = 0, mask = 1; i < 32; i++, mask <<= 1) {
            int bitCounts = 0;
            for (int j = 0; j < n; j++) {
                if (nums[j] & mask) bitCounts++;
                if (bitCounts > n / 2) {
                    major |= mask;
                    break;
                }
            }
        } 
        return major;
    } 
};