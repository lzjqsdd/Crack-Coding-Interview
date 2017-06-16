//同398,给定一个单链表，每次随机输出一个节点的值，使得输出这些值的概率都相同，且预先不知道链表的长度

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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head):head(head) {}
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode *p = head;
        int cnt = 0,res=0;
        while(p)
        {
            cnt++;
            if(rand()%cnt == 0) res = p->val;
            p = p->next;
        }
        return res;
    }
private:
    ListNode *head;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */