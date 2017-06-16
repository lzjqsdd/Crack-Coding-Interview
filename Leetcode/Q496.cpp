//496. Next Greater Element I
//题意:给定两个数组,数组1是数组2的子集.在数组2中,找出数组1中每个元素的Next Greater元素,如果不存在返回


//以下方法会把原有的顺序打乱.这里的next greater只的是索引上的next,如果是数字上的next,则使用下列方法
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<pair<int,int>> p;
        for(int i=0;i<nums.size();++i) p.push_back(make_pair(nums[i],i));
        sort(p.begin(),p.end());
        vector<int> result;
        for(auto x:findNums)
        {
            auto pos = upper_bound(p.begin(),p.end(),x);
            if(pos!= p.end()) result.push_back(pos->second);
            else result.push_back(-1);
        }
        return result;
    }
};

//AC,栈也可以使用双指针来处理.用指针来维护栈顶和栈底
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        stack<int> s;
        unordered_map<int,int> m;
        for(auto n:nums)
        {
            while(!s.empty() && s.top() < n)
            {
                m[s.top()] = n;
                s.pop();//解决了一个出一个
            }
            s.push(n);
        }
        for(auto n:findNums) result.push_back(m.count(n) ? m[n]:-1); //m.count()找key是否存在
        return result;
    }
};

//题意理解错误:nextgrater值得是nums1中的数在nums2中对应的那个数,找nums2中该数是否有nextgreater
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        stack<int> s;
        unordered_map<int, int> m;
        for (int n : nums) {
            while (s.size() && s.top() < n) {
                m[s.top()] = n;
                s.pop();
            }
            s.push(n);
        }
        vector<int> ans;
        for (int n : findNums) ans.push_back(m.count(n) ? m[n] : -1); //m.count()找key是否存在
        return ans;
    }
};