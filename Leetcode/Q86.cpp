//题意：给定链表，以及x，所有小于x的节点都排在大于x的节点之前，调整过程中不能改动之间的相对顺序
// 1 4 3 2 5 2
// 1 2 2 | 4 3 5

//思路：定义两个链表指针，一个用来链接小于x,一个用于大于x的

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 //Submit:1 AC
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode*less = new ListNode(0);
        ListNode *gre = new ListNode(0);
        ListNode *l = less,*g = gre;
        ListNode *cur = head;
        while(cur)
        {
            if(cur->val < x) {less->next = cur;less = less->next;}
            else {gre->next = cur; gre = gre->next;}
            cur = cur->next;
        }
        gre->next = NULL;
        less->next = gre->next;
        return l->next;
    }
};