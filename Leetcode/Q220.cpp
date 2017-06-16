//题意：给定一组整数，以及t,k.判断是否存在两个数，其差的绝对值最多为t并且
//两个数的索引值之差最多为k

//思路：先排序，然后锁定其中一个，另一个使用二分查找(upper_bound)


class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
         if(nums.size() == 0) return false;
        vector<pair<int,int>> a;
        for(int i = 0;i<nums.size();++i) a.push_back(make_pair(nums[i],i));
        sort(a.begin(),a.end());
        auto cmp = [](const pair<int,int>&p1,const pair<int,int>&p2){return p1.first < p2.first;};
        for(int i=0;i<a.size()-1;++i) //如果不判断是否NUms为0，这里是致命的，size()-1非常大！！！！    
        {
            //nums[i]+t是满足条件最大的。如果序列中比这个最大的都大，说明与nums[i]相关的数不存在
            //如果有满足条件的，则nums[i]+t >= nums[j].如果不满足，则如果使用upper_bound查找，则返回的是第一个元素。 
            auto p = std::upper_bound(a.begin()+i+1,a.end(),make_pair(a[i].first+t,0),cmp);
            ///if(p == a.begin()+i+1) continue;
            //else //如果有，则看这些里面的索引之差是否满足条件
            //{
                for(auto it = a.begin()+i+1; it != p; ++it)
                {
                    if(abs(it->second - a[i].second) <=k) return true;
                }
            //}
        }
        return false;
    }
};