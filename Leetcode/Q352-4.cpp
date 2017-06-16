//352. Data Stream as Disjoint Intervals
//题意：给定数据输入流，总结每次输入后的不相邻的区间
//比如，输入次序分别位1,3,7,2,6...
//则每次的区间变化为
//[1,1]
//[1,1],[3,3]
//[1,1],[3,3],[7,7]
//[1,3],[7,7] 2把区间[1,3]连起来了
//[1,3],[6,7]

//思路：二叉搜索树
//每次加入新的区间，看是否可以合并。加入规则，如果iv->rchild小于p->lchild，加入左子树，如果iv->leftchild大于p->rchild，加入右子树
//合并左子树到父节点，不需要调整父节点的右子树，

//Definition for an interval.

#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class SummaryRanges
{
  public:
    /** Initialize your data structure here. */
    void addNum(int val)
    {
        Interval iv(val, val);
        auto it = st.lower_bound(iv); //找到第一个start大于val的区间
        if (it != st.begin() && (--it)->end + 1 < val)
            ++it;                   //如果在前一个区间的end不小于val,可以在前一个区间合并
        int start = val, end = val; //即将加入的新区间
        while (it != st.end() && val + 1 >= it->start && val - 1 <= it->end) //后两个条件，可以分别表示和前后两个区间的连接条件
        {
            start = min(it->start, start);
            end = max(it->end, end);
            it = st.erase(it);
        }
        st.insert(it, Interval(start, end)); //在it之前插入
        //example
        //[5,7][9,10]插入[8,8]
        //it指向[5,7],得到[5,8],erase后it指向[9,10]
        //
    }

    vector<Interval> getIntervals()
    {
        vector<Interval> result;
        for (auto val : st)
        {
            result.push_back(val);
        }
        return result;
    }

  private:
    struct Cmp
    {
        bool operator()(const Interval &a, const Interval &b)
        {
            return a.start < b.start;
        }
    };
    set<Interval, Cmp> st;
};

int main()
{
    //vector<int> test = {1,3,7,2,6,4,8,9,10,13,12,11,5,-1,0,20,24,34,25};
    vector<int> test = {6, 6, 0, 4, 8, 7, 6, 4, 7, 5};
    SummaryRanges sr;
    for (auto x : test)
    {
        sr.addNum(x);
        sr.getIntervals();
    }
}