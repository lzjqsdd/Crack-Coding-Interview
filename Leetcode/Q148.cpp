//对单链表进行排序，要求空间O(1),时间O(nlogn)
//merge-sort
#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
  public:
    ListNode *sortList(ListNode *head)
    {
        return sort_merge(head);
    }

    ListNode *merge(ListNode *lstart, ListNode *rstart)
    {
        cout << "merge" << endl;
        ListNode *result = new ListNode(0); //head部分最后要去掉
        ListNode *head = result;
        while (lstart != NULL && rstart != NULL)
        {
            if (lstart->val < rstart->val)
            {
                result->next = lstart;
                result = result->next; //加入合并集合中
                lstart = lstart->next; //指针下移
            }
            else
            {
                result->next = rstart;
                result = result->next;
                rstart = rstart->next;
            }
        }

        while (lstart != NULL)
        {
            result->next = lstart;
            result = result->next;
            lstart = lstart->next;
        }
        while (rstart != NULL)
        {
            result->next = rstart;
            result = result->next;
            rstart = rstart->next;
        }
        return head->next; //head头无意义
    }

    //sort的链表结尾都是NULL
    ListNode *sort_merge(ListNode *head)
    {

        //如果只有一个就返回
        if(head!=NULL && head->next==NULL) return head;

        ListNode *l = head;
        if (l != NULL)
        {
            ListNode *mid = FindMid(l);
            cout << mid->val << endl;
            ListNode *rmid = mid->next; //右半部分
            mid->next = NULL;           //左半部分尾部为NULL
            ListNode *lstart = sort_merge(l);
            ListNode *rstart = sort_merge(rmid);
            return merge(lstart, rstart);
        }
    }

    ListNode* FindMid(ListNode *s)
    {
        cout << "FindMid" << endl;
        //使用快慢指针定位中点
        if (s == NULL) return NULL;

        ListNode *slow = s;
        ListNode *fast = s;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

int main()
{
    ListNode *head = new ListNode(0);
    ListNode *ss = head;
    //head->next = new ListNode(10); head = head->next;
    //head->next = new ListNode(2);head = head->next;
    //head->next = new ListNode(1);head = head->next;
    //head->next = new ListNode(5);head = head->next;
    //head->next = new ListNode(4);head = head->next;
    //head->next = new ListNode(6);head = head->next;
    //head->next = new ListNode(11);head = head->next;
    //head->next = new ListNode(7);head = head->next;
 

    Solution s;
    ListNode *result = s.sortList(ss);
    //ListNode *result = ss;
    while (result != NULL)
    {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
    return 0;
}
