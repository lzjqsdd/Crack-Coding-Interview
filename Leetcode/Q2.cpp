#include <iostream>
#include <cstdio> 
#include <cstdlib>
#include <string>
using namespace std;

struct ListNode{
	int val;
	struct ListNode *next;
};

struct ListNode * addTwoNumbers(struct ListNode *l1,struct ListNode *l2)
{
	struct ListNode *ll1;
	struct ListNode *ll2;
	struct ListNode *tmp;
	struct ListNode *p,*q;
	int len1=0;
	int len2=0;
	for(ll1=l1;ll1!=NULL;ll1 = ll1->next) len1++;
	for(ll2=l2;ll2!=NULL;ll2 = ll2->next) len2++;

	if(len1<len2) {tmp=l1;l1=l2;l2=tmp;}

	for(p=l1,q=l2;q!=NULL;p=p->next,q=q->next)
	{
		int sum = p->val+q->val;
		if(sum < 10) p->val=sum;
		else {
		    p->val = sum-10;
		    if(p->next==NULL) {
				tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
				tmp->next=NULL;
				tmp->val = 0;
				p->next = tmp;
			}
		    p->next->val += 1;
		}
	}

	for(p;p!=NULL;p=p->next)
	{
		if(p->val>=10)
		{
			p->val = p->val-10;
			if(p->next==NULL) {
				tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
				tmp->next=NULL;
				tmp->val = 0;
				p->next = tmp;
			}
			p->next->val+1;
		}
	}
	return l1;

}

int main()
{
	/*
	struct ListNode *data=NULL;
	struct ListNode *p=NULL;
	p=data;
	for(int i=0;i<10;i++)
	{
		struct ListNode *tmp = (ListNode*)malloc(sizeof(ListNode));
		tmp->val = i;
		tmp->next = p;
		p = tmp;
	}
	*/
	struct ListNode *l1 = (struct ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode *l2 = (struct ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode *p;

	l1->val = 0;
	l1->next=NULL;
	l2->val = 0;
	l2->next=NULL;
	p = addTwoNumbers(l1,l2);

	for(p;p!=NULL;p=p->next)
		cout<<p->val<<endl;
}

//上述方法使用了额外空间，而下面方法仅仅处理最后进位的额外空间
//第二遍 AC
//两个非空链表表示数组，8->7->2表示287,5->4->3表示345，求相加结果
//刚好从链表开始的位置对齐进行相加

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *p = l1; //用l1表示最终的结果
		ListNode *q = l2;
		ListNode *par = NULL;
		while(p!=NULL && q!=NULL)
		{
			p->val += q->val; //先不处理余数
			par = p;
			p = p->next;
			q = q->next;
		}
		//这里以l1表示结果，所以如果l1比较长，则不处理。
		//如果l2较长，把未加的l2的部分续上(对应的是p == NULL)
		if(p == NULL) par->next = q;

		//遍历l1处理进位
		p = l1;
		while(p!=NULL && p->next!=NULL)
		{
			if(p->val >= 10)
			{
				p->val-= 10;
				p->next->val ++;
			}
			p = p->next;
		}
		while(p!=NULL && p->val >= 10)
		{
			p->val -= 10;
			p->next = new ListNode(1);
			p = p->next;
		}
		return l1;
    }
};