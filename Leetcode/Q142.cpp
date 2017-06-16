//题意：给定一个链表（有环），给出环开始的地方
//先通过快慢指针得到相遇的位置，然后快指针速度置为1，慢指针从头开始，则相遇时即为环开始节点


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
    ListNode *detectCycle(ListNode *head) {
        ListNode*fast = head;
        ListNode*slow = head;
        while(fast && fast->next) //初始条件两个相同，所以while这里的条件使用fast来确定
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) break;
        }
        if(fast == NULL || fast->next==NULL) return NULL; //如果没有环就返回NULL
        slow = head;
        while(fast!=slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};

//或者对地址采用hash方法