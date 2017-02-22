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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *p = head;
        while(p!=NULL && p->next!=NULL)
        {
            ListNode *q = p->next;
            if(p->val == q->val)
            {
                p->next = q->next;
            }
            else
                p = p->next;
        }
        return head;
    }
};