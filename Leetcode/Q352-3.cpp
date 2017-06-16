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
        auto it = st.lower_bound(Interval(val, val));
        int start = val, end = val;
        if (it != st.begin() && (--it)->end + 1 < val) //[5,7],[9,10]插入8，it为[9,10],但是要插入到[5,7]中，所以不能只比较start
            it++;
        while (it != st.end() && val + 1 >= it->start && val - 1 <= it->end) //合并区间
        {
            start = min(start, it->start);
            end = max(end, it->end);
            it = st.erase(it);
        }
        st.insert(it, Interval(start, end));
    }

    vector<Interval> getIntervals()
    {
        vector<Interval> result;
        for (auto val : st)
        {
                result.push_back(val);
                cout << val.start << "->" << val.end << " ";
        }
        cout <<endl;
        return result;
    }

  private:
    struct Cmp
    {
        bool operator()(Interval a, Interval b) { return a.start < b.start; }
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