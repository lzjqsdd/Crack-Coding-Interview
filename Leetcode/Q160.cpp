 //Intersection of Two Linked Lists
A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
//找到开始比较的位置，因为如果有重合部分，则尾部一定是对其的。比较两个的长度差


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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
          ListNode *pa = headA;
          ListNode *pb = headB;
          int lena = 0,lenb=0;
          while(pa!=NULL) {lena++;pa = pa->next;}
          while(pb!=NULL) {lenb++;pb = pb->next;}
          
          int tmp = abs(lena-lenb);
          if(lena > lenb) {pa = headA;pb = headB;}
          else {pa = headB; pb = headA;} //pa为较长的哪个;
    
          if(tmp > 0)
            while(tmp--) pa = pa->next;
          
          while(pa!=NULL && pb!=NULL)
          {
            if(pa == pb) return pa;
            else 
            {
              pa = pa->next;
              pb = pb->next;
            }
          }
          return NULL;
    }
};