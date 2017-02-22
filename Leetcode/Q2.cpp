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
