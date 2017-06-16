//题意：给定一个单链表，升序排列，把它转换成一个平衡的BST
//思路：因为需要平衡的BST,而原有序列为有序，所以很朴素的想法，把原有序列等分，然后作为根节点。
//因为原序列位链表，所以查找中点的代价为O(n),而二分建树需要O(logn),所有总复杂度为O(nlogn)

//二分每次指定要分的长度，以及起始的位置。
#include <iostream>
#include <vector>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;
        
        int l = 0,r = 0;
        ListNode *p = head;
        while(p) {r++;p=p->next;}
        TreeNode *root = NULL;
        buildTree(head,l,r-1,root); //传递的应该按照下标顺序，r-1,而不是r
        return root;
    }

    void buildTree(ListNode *head,int l,int r,TreeNode *&root)
    {
        if(head == NULL) return;
        if(l <= r)
        {
            int step = (r - l +1 )/2; //让中点偏右，(r-l)/2让中点偏左。
            ListNode*mid = head;
            for(int i=0;i<step;++i) mid = mid->next; //定位中点
            root = new TreeNode(0);
            root->val = mid->val;
            buildTree(head,l,l+step-1,root->left);
            buildTree(mid->next,l+step+1,r,root->right);
        }
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    ListNode *p = head;
    p->next = new ListNode(2); p = p->next;
    p->next = new ListNode(3); p = p->next;
    p->next = new ListNode(4);
    Solution s;
    s.sortedListToBST(head);
}

