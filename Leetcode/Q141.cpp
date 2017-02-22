/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 //使用快慢指针判断是不是有环
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL) return false;
        ListNode *p = head;
        ListNode *p2 = head->next;
        while(true)
        {
            if(p==p2) return true;
            if(p==NULL || p2==NULL) return false; //说明走到头了
            if(p!=NULL)
                p = p->next;
            if(p2!=NULL)
            {
                p2 = p2->next;
                if(p2!=NULL) p2 = p2->next;
            }
            
        }
    }
};