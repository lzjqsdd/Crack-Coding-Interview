//题目：给定一组区间，求出每个区间最小的右区间。右区间：区间j的右界大于或者等于i的左界
//如果不存在，返回-1

//思路:BST建立区间树，方便查找第一个满足条件的元素

struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};


#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    /*
    vector<int> findRightInterval(vector<Interval>& intervals) {
        set<IV_IDX,Cmp> st;
        //auto it = st.begin();
        for(int i=0;i<intervals.size();++i)
            st.insert(IV_IDX(intervals[i],i)); //建立BST
        vector<int> result;
        //for(auto it = st.begin();it!=st.end();++it)
        //    cout << it->idx << endl;
        for(auto val:intervals)
        {
            auto it = st.lower_bound(IV_IDX(val,0)); //找到的是当前元素的位置
            //cout << it->idx << endl;
            ++it; //往后移一个元素进行比较查找
            while(it!=st.end() && it->iv.start < val.end) ++it;
            if(it == st.end()) result.push_back(-1);
            else result.push_back(it->idx);
        }
        return result;
    }
    */

    //题目假设了所有区间的起点不同，所以可以使用map
     vector<int> findRightInterval(vector<Interval>& intervals) {
         map<int,int> hash;
         for(int i=0;i<intervals.size();++i)
            hash[intervals[i].start] = i;
        
        vector<int> result;
        for(auto in:intervals)
        {
            auto it = hash.lower_bound(in.end); //大于end的最接近的区间
            if(it != hash.end()) result.push_back(it->second);
            else result.push_back(-1);
        }
        return result;
     }
private:
    struct IV_IDX
    {
        Interval iv;
        int idx;
        IV_IDX(Interval iv,int idx):
            iv(iv.start,iv.end),idx(idx){}
    };
    struct Cmp
    {
        bool operator()(const IV_IDX &a,const IV_IDX &b) {return a.iv.start < b.iv.start;}
    };
};

int main()
{
    Solution s;
    vector<Interval> test;
    test.push_back(Interval(1,4));
    test.push_back(Interval(2,3));
    test.push_back(Interval(3,4));
    vector<int> rst =  s.findRightInterval(test);
    for(auto i:rst) cout << i << endl;
    return 0;
}