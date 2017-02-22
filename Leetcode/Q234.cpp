#include <iostream>
#include <string>
#include <cmath>
using namespace std;

//思路：
//Step1:快慢指针定位终点
//Step2:后半段置逆
//Step3:比较前半段和后半段是不是相同

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
    bool isPalindrome(ListNode* head) {

        //排除长度为1，2，3的

        //快慢指针定位终点
        ListNode *p1 = head;
        ListNode *p2 = head;

        while(p2!=NULL && p2->next!=NULL)
        {
            p1 = p1->next;
            p2 = p2->next->next;
        }

        //有两种情况，p2==NULL(链表为偶数)或者p2->next==NULL(链表为奇数)
        //abcddcba(nil) p1位于第一段abcd之后，后半段的起点
        //acbdcba(nil) 同样p1位于第一段abc之后，后半段起点前一个
        //所以p1作为第一段的终点

        ListNode *sp; //第二段的head
        if(p2==NULL) sp = p1;
        else sp = p1->next;

        ListNode *after = sp->next;
        sp->next = NULL; 
        ListNode *prev = sp;
        sp = after;

        while(sp!=NULL)
        {
            after = sp->next;
            sp->next = prev;
            prev = sp;
            sp = after;
        }

        //第二段起点为prev
        ListNode *p = head;
        ListNode *rp = prev;
        while(p!=p1 && rp!=NULL)
        {
            if(*p != *rp) return false;
        }
        return true;
    }
};

