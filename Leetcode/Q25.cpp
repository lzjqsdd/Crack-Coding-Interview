//和24类似，但是不仅仅是反转两个了。每次可以指定k，每次反转k个元素
//不够不翻了
//比如1->2->3->4->5->6->7->8
//k=3,3->2->1->6->5->4->7->8

//对于反转两个，直接设置两个指针p,q可以解决，但是对于k个，可以通过栈来完成反转
//但是如果是栈的话，栈的大小是随着k的增加增加，空间复杂度为O(n)
//考虑沿用24的解决思路：
//仍然设置par，nextp，衔接处理思路不变
//对中间的交换过程{q->next = p;p=NULL;}加以改造。

//则思路集中在子问题(如何反转一个K长度的链表)

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *result = new ListNode(0);
        ListNode *par = result; //这个前导节点最终不要
        ListNode *nextp = head; //初始化下一个要处理的节点为head
        ListNode *p=NULL;
        while(nextp) //如果还有可以反转的,注意这里可能余一个节点，只需要连接上即可
        {
            p = nextp;
            cout << "p:" << p->val << endl;

            //获取下一个nextp
            int kk = k;
            ListNode *pp = p;
            while(pp && kk)
            {
                kk--;
                pp = pp->next;
            }

            //和Q24同样的处理方法
            if(kk==0)
            {
                nextp = pp;
                ListNode *nextpar = p;
                par->next = reverseSingle(p,k);
                par = nextpar;
            }
            else //说明不足k个
            {
                par->next = p;break;
            }

        }
        return result->next;
    }


    //反转长度为k的链表
    ListNode* reverseSingle(ListNode* head,int k)
    {
        ListNode *pre = NULL,*p = NULL, *nextp = head;
        while(nextp && k)
        {
            k--;
            p = nextp;
            nextp = p->next;
            p->next = pre;
            pre = p;
        }
        return pre; //最后一个节点成了首节点
    }
};

int main()
{
    ListNode *test = new ListNode(1);
    ListNode *p = test;
    p->next = new ListNode(2);p = p->next;
    p->next = new ListNode(3);p = p->next;
    p->next = new ListNode(4);p = p->next;
    p->next = new ListNode(5);p =p->next;

    Solution s;
    int x = 2;
    cin >> x;
    //ListNode *res = s.reverseSingle(test,2);
    ListNode *res = s.reverseKGroup(test,x);
    while(res)
    {
        cout << res->val << ",";
        res = res->next;
    }
    cout << endl;
    return 0;

}