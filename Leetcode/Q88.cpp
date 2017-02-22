//常规方式，用额外的数组记录最后的合并结果。


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.push_back(INT_MAX);m++;
        nums2.push_back(INT_MAX);n++;
        vector<int> result;
        int i=0,j=0;
        while(i!=m && j!=n)
        {
            if(nums1[i] <= nums2[j])
            {
                result.push_back(nums1[i]);
                i++;
            }
            else
            {
                result.push_back(nums2[j]);
                j++;
            }
        }
        result.erase(result.end()-1);
        nums1.swap(result);
    }
};

//如果淡出的插入到nums1中，则vector的插入效率非常低(vector是线性表)。可以先把nums2加入到nums1末尾，然后对两段采用交换
//的方式处理
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.insert(nums1.end(),nums2.begin(),nums2.end());
        auto it1 = nums1.begin();
        auto it2 = nums2.begin()+m;
        while(it1 != nums1.begin()+m)
        {
            if(*it1 < *it2)
                ++it1;
            else
            {
                int tmp = *it1;
                *it1 = *it2;
                *it2 = tmp;
                ++it1;
                ++it2;
            }
        }

    }


//倒着不会影响nums1之前的数据

class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int i = m - 1, j = n - 1, position = m + n - 1;
        while (j >= 0) {
            nums1[position--] = i >= 0 && nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
        }
    }
};


void merge(vector<int>&nums1,int m,vetor<int>nums2,int n)
{
    int i = m-1;
    int j = n-1;
    int k = m+n-1;
    while(j >= 0 && i>=0)
    {
        nums1[k--] = nums1[i] > nums2[j] ? nums1[i--]:nums2[j--];
        nums1[k--] = (i>=0 && nums1[i] > nums2[j]) ? nums1[i--]:nums2[j--];
    }
}