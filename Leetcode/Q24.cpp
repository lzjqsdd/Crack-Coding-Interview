//给定一个链表，每次交换两个节点，如：
//1->2->3->4变为2->1->4->3;

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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL) return NULL;
    
        ListNode *start;
        if(head->next!=NULL)
            start = head->next;
        else
            start = head;
    
        ListNode *p = head;        
        while(p!=NULL && p->next!=NULL)
        {
            ListNode *pn = p->next; //pn为交换的第二个数
            ListNode *nextP = p->next->next;
            if(pn->next!=NULL)
            {
                if(pn->next->next!=NULL)
                    p->next = pn->next->next; //与下一对连接
                else
                    p->next = pn->next;
            }
            else
                p->next = NULL;
                
                
            pn->next = p;
            p = nextP;
        }
        return start;
    }
};

//上次的做法是优先建立每对之间的连接，比如先考虑把第一个节点连到第四个节点上
//然后才考虑当前对的连接。


//第二遍
//每次先考虑反转，反转后把反转的节点连接到已经处理的序列上
//所以维护以下几个指针
//(1)par表示已经处理完的节点的最后。用于连接下面处理好的节点对
//(2)p 表示当前处理的节点对的第一个
//(3)q 表示当前处理的节点对的第二个
//(4)nextp 表示下次要处理的节点对的第一个（因为反转后next指向了前面，所以在修改next之前必须保存下次要处理的节点)

//速度比之前版本又快了。。。(^-^)
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
    ListNode* swapPairs(ListNode* head) {
        ListNode *result = new ListNode(0);
        ListNode *par = result; //这个前导节点最终不要
        ListNode *nextp = head; //初始化下一个要处理的节点为head
        ListNode *p=NULL,*q=NULL;
        while(nextp) //如果还有可以反转的,注意这里可能余一个节点，只需要连接上即可
        {
            p = nextp;
            q = p->next;
             p->next = NULL; //p的next下次会由par完成。
            if(q) //如果有两个节点
            {
                //先保留下一组
                nextp = q->next;
                q->next = p;
                par->next = q; //连接前面已经处理完的
                par = p; //比如 1->2->3->4中，1为par,2为p，3为q
            }
            else
            {
                par->next = p;break;
            }
        }
        return result->next;
    }
};