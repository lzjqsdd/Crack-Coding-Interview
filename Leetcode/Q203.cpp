//移除链表中给定val的节点
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
    ListNode* removeElements(ListNode* head, int val) {
        
        while(head!=NULL && head->val == val) //移除第一个
            head = head->next;
        
        if(head != NULL)
        {
            ListNode *prev = head;
            ListNode *p = head->next;
            while(p!=NULL)
            {
                if(p->val == val) 
                    prev->next = p->next;
                else
                    prev = p;
                p = p->next;
            }
        }
        
        return head;
    }
};