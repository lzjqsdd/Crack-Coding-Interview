//给定两个链表，每个节点表示一个位
//7->2->4->3
//5->6->4

//思路1：先按对应的位相加，存到结果中。然后在结果中把溢出的节点进位处理


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //定位的方法：确定两个链表的长度，如果较长的那个先加到结果中
        int n1 = 0,n2=0,carry = 0;
        
        ListNode *cur1 = l1,*cur2 = l2;
        while(cur1) {n1++;cur1 = cur1->next;}
        while(cur2) {n2++;cur2 = cur2->next;}
        ListNode* res = NULL;
        while(n1 >0 && n2>0)
        {
            int sum = 0;
            if( n1 >= n2 ){ sum += curr1->val; curr1=curr1->next; n1--;}
            if( n2 >  n1 ){ sum += curr2->val; curr2=curr2->next; n2--;}
        }
    }
};

//思路2：栈/递归（天然栈）