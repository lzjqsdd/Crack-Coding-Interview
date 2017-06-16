//Remove Nth Node From End of List
//题意：给定链表，移除倒数第N个节点，并返回head
//题目假定n输入始终合法

//第一遍思路：把到时第n个转换为正的第len-n+1个。

//第二遍
//思路:如果只有一个节点，移除第一个之后链表为空.如果删除的是head呢？
//two-pointers
//让第一个指针先走n步，第二个指针开始走，当第一个指针达到尾部时，第二个指针刚好位于第n个节点
//因为要删除的是第n个节点，定位到第n-1个节点，方便删除。

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head,*q = head;
        while(n--) p = p->next;
        if(p == NULL) //说明删除的是头节点
            return head->next;
        while(p && p->next)
        {
            q = q->next;
            p = p->next;
        }

        if(q->next == NULL) return NULL; //只有一个节点
        else
        {
            q->next = q->next->next;
        }
        return head;
    }
};