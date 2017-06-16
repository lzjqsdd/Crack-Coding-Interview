//合并两个有序的链表

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * result = new ListNode(0);
        ListNode *p = result;
        while(l1 && l2) //如果使用了l1&&l1->next,则会少最后一个元素。只要l1不为空，就说明有值
        {
            if(l1->val < l2->val)
            {
                p->next = l1;
                l1 = l1->next;
            }
            else
            {
                p->next = l2;
                l2 = l2->next;
            }
            p=p->next;
        }
        while(l1) {p->next = l1;l1=l1->next;p = p->next;}
        while(l2) {p->next = l2;l2=l2->next;p = p->next;}
        return result->next;
    }
};