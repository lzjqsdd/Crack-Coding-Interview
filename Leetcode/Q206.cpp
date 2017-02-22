// 用栈做，取巧了
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
    ListNode* reverseList(ListNode* head) {
        stack<int> tmp;
        ListNode *prev = NULL;
        ListNode *curr = head;
        while(curr!=NULL)
        {
            ListNode *nextTmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTmp;
        }
        return prev;
    }
};