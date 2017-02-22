[3,2,1]
[1]
[1,2]
[1,1]
[1,2,3,4,5,6]
[1,1,1,3,4,5,6,7]
[-2147483648]
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        int max1 = nums[0];
        int max2 = nums[0];
        int max3 = nums[0];
        if(n == 1) return nums[0];
        //else if(n == 2) return nums[0] > nums[1] ? nums[0]:nums[1]; //µÚ¶þ´ó
        else
        {
            for(int x:nums)
            {
                if(x > max1)
                {
                    max3 = max2;
                    max2 = max1;
                    max1 = x;
                }
                else if(x == max1) continue;
                else if(x > max2)
                {
                    max3 = max2;
                    max2 = x;
                }
                else if(x == max2) continue;
                else if(x > max3)
                {
                    max3 = x;
                }
            }
        }
        cout << max1 << max2 << max3 << endl;
        if(max3 == INT_MIN)
        {
            return max1;
        }
        else
            return max3;
        
    }
};