//题意：合并k个有序的链表
//k路归并问题
//思路：参考经典归并问题，每次选择两个中较小的那个加入结果中。我们可以很方便知道两个首部元素大小。
//但是对于k个，要想在O(1)时间内知道哪个元素最小，可以使用小顶堆。

//测试（使用map)，map维护了有序key，第一个元素key总是最小的
//map和multimap都是有序关联容器

/*
template<class T> struct cmp
{
    bool operator()(T * lhs, T* rhs)
    {
        return lhs->val < rhs-val;
    }
};*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct cmp
{
    bool operator()(ListNode *lhs, ListNode *rhs)
    {
        return lhs->val < rhs->val;
    }
};

class Solution
{
  public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        multimap<ListNode *,int , cmp> m; //这个cmp是放在模板中，在实际使用时会变成cmp();
        int k = lists.size();
        ListNode *result = new ListNode(0);
        for (int i = 0; i < k; ++i)
        {
            if(lists[i] == NULL) continue; //这里提交出错了，必须考虑[[],[1,2]]的情况
            m.insert(make_pair(lists[i],i));
            lists[i] = lists[i]->next;
        }

        ListNode *p = result;
        while(!m.empty())
        {
            p->next = m.begin()->first; //每次取最大值
            p = p->next;
            int index = m.begin()->second;
            m.erase(m.begin());
            if(lists[index]!=NULL)
            {
                m.insert(make_pair(lists[index],index));
                lists[index] = lists[index]->next;
            }
        }
        return result->next;
    }
};

int main()
{
    vector<ListNode *> test;

    ListNode *l1 = new ListNode(4);
    ListNode *p = l1;
    p->next = new ListNode(19); p = l1->next;
    p->next = new ListNode(23); p = l1->next;
    p->next = new ListNode(24); p = l1->next;
    test.push_back(l1);


    test.push_back(new ListNode(6));
    test.push_back(new ListNode(8));
    test.push_back(new ListNode(1));
    test.push_back(new ListNode(10));

    Solution s;
    s.mergeKLists(test);
}


//heap方式
struct cmp
{
    bool operator()(pair<ListNode*,int>lhs, pair<ListNode*,int> rhs)
    {
        return lhs.first->val > rhs.first->val;
    }
};

class Solution
{
  public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        vector<pair<ListNode*,int>> kheap;
        int k = lists.size();
        ListNode *result = new ListNode(0);
        for (int i = 0; i < k; ++i)
        {
            if(lists[i] == NULL) continue; //这里提交出错了，必须考虑[[],[1,2]]的情况
            kheap.push_back(make_pair(lists[i],i));
            lists[i] = lists[i]->next;
        }

        std::make_heap(kheap.begin(),kheap.end(),cmp());

        ListNode *p = result;
        while(!kheap.empty())
        {
            pop_heap(kheap.begin(),kheap.end(),cmp());
            p->next = kheap.back().first;
            p = p->next;
            int index = kheap.back().second;
            
            kheap.pop_back();
            
            if(lists[index]!=NULL)
            {
                kheap.push_back(make_pair(lists[index],index));
                push_heap (kheap.begin(),kheap.end(),cmp());
                lists[index] = lists[index]->next;
            }
        }
        return result->next;
    }
};

//学习到的：cmp()用在函数中，cmp用在模板中
//make_heap
//pop_heap + pop_back
//push_back + push_heap


//第二遍：使用优先队列priority_queue来记录k中最小的。

//这里队列使用的比较函数需要自定义

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


struct cmp
{
    public:
        bool operator()(const ListNode* a,const ListNode *b)
        {
            return a->val > b->val;
        }
};

class Solution {
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) {

            priority_queue<ListNode*,vector<ListNode*>,cmp> pq;
            ListNode *result = new ListNode(0);
            ListNode *p = result;
            for(int i=0;i<lists.size();++i)
                if(lists[i]) pq.push(lists[i]);

            while(!pq.empty())
            {
                //取最小的,同时压入该list的后一个元素
                ListNode* t = pq.top();
                pq.pop();
                if(t->next) pq.push(t->next);

                p ->next = t;
                p = p->next;
            }

            return result->next;
        }
};


int main()
{
    vector<ListNode *> test;

    ListNode *l1 = new ListNode(4);
    ListNode *p = l1;
    p->next = new ListNode(19); p = l1->next;
    p->next = new ListNode(23); p = l1->next;
    p->next = new ListNode(24); p = l1->next;
    test.push_back(l1);


    test.push_back(new ListNode(6));
    test.push_back(new ListNode(8));
    test.push_back(new ListNode(1));
    test.push_back(new ListNode(10));

    Solution s;
    ListNode * res = s.mergeKLists(test);
    while(res)
    {
        cout << res->val << ",";
        res = res->next;
    }
    cout << endl;
}

//[]
//[[],[2,3,4],[3,5,6]]
//[[1,2,3]]
//[[1,2],[2,3,4,5],[-1,1,4]]