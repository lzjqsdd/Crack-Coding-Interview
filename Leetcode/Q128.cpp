//题意：给定一个未排序的序列，求出最长的连续序列。不要求原来有序。3,2,1,4也是连续的。

//思路：建立连续序列的集合，如果后续的元素可以将当前集合连接起来，则形成行的序列。
//需要维护每个集合的区间边界
//使用并查集来做。


//并查集之所以查的快，其记录是以元素所属集合id为出发点，每个元素都有个集合的记录。


//如下方案有些像并查集，但是合并的过程只考虑了边界的元素
//find的复杂度为logn,如果用unordered_map查询速度为O(1)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        map<int,int> dict;
        for(auto x:nums)
        {
            if(dict.find(x) == dict.end())
            {
                int left = dict.find(x-1) != dict.end() ? dict[x-1] : 0;
                int right = dict.find(x+1) != dict.end() ? dict[x+1] : 0;
                int sum = left + right +1;
                dict[x] = sum;
                res = max(res,sum);

                //扩展边界元素所属集合的长度
                dict[x-left] = sum;
                dict[x+right] = sum; 
            }
        }
        return res;
    }
};