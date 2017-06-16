#include "ListNode.h"
#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>

using namespace std;

class Solution {
private:
struct cmp
{
    bool operator ()(const ListNode *a, const ListNode *b)
    {
            return a->val > b->val;
    }
};
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int n = lists.size();
        if(n == 0)return NULL;
        ListNode node(0), *res = &node;
        priority_queue<ListNode*, vector<ListNode*>, cmp> que;
        for(int i = 0; i < n; i++)
            if(lists[i])
                que.push(lists[i]);
        while(!que.empty())
        {
            ListNode * p = que.top();
            que.pop();
            res->next = p;
            res = p;
             
            if(p->next)
                que.push(p->next);
        }
        return node.next;
    }
};

int main()
{
	int *p = (int *)malloc(1024);
	for(int i=0;i<256;i++) cout << *p++ << endl;
	Solution s;
}
