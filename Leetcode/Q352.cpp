//352. Data Stream as Disjoint Intervals
//题意：给定数据输入流，总结每次输入后的不相邻的区间
//比如，输入次序分别位1,3,7,2,6...
//则每次的区间变化为
//[1,1]
//[1,1],[3,3]
//[1,1],[3,3],[7,7]
//[1,3],[7,7] 2把区间[1,3]连起来了
//[1,3],[6,7]

//思路：二叉搜索树
//每次加入新的区间，看是否可以合并。加入规则，如果iv->rchild小于p->lchild，加入左子树，如果iv->leftchild大于p->rchild，加入右子树
//合并左子树到父节点，不需要调整父节点的右子树，

//Definition for an interval.

#include <iostream>
#include <vector>
using namespace std;

struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
};

typedef struct Node{
    Interval iv;
    Node *lchild;
    Node *rchild;
    Node *parent;
    Node(Interval iv):
        iv(iv),
        lchild(NULL),
        rchild(NULL),
        parent(NULL){}
}Node;

class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        root = NULL;
    }
    
    void addNum(int val) {

        Interval iv(val,val);
        if(root == NULL)
            root = new Node(iv); //第一次建立根
        else //插入区间
        {
            Node *node = new Node(iv); //待插入
            Node *current = root;
            while(current) //插入新的节点
            {
                if(val < current->iv.start)
                {
                    if(current->lchild != NULL) current = current->lchild;
                    else {current->lchild = node; node->parent = current; break;}
                }
                else if(val > current->iv.end)
                {
                    if(current->rchild != NULL) current = current->rchild;
                    else {current->rchild = node; node->parent = current; break;}
                }
                else break;
                //相等时说明在已经存在的区间内
            }
            //合并区间
            current = node;
            while(current->parent != NULL)
            {
                cout << "x" << current->iv.start << endl;
                Node *p = current->parent;
                if(p->lchild == current && p->iv.start - current->iv.end == 1) //左子树可合并进来
                {
                    p->iv.start = current->iv.start;
                    //通过旋转来维持BST性质
                    if(current->lchild == NULL && current->rchild == NULL)
                        p->lchild = NULL;
                    else if(current->lchild == NULL && current->rchild != NULL)
                        p->lchild = current->rchild;
                    else if(current->lchild != NULL && current->rchild == NULL)
                        p->lchild = current->lchild;
                    else //左右子节点都存在
                    {
                        p->lchild = current->rchild;
                        Node *q = current->rchild;
                        while(q->lchild != NULL) q = q->lchild;
                        q->lchild = current->lchild;
                        cout << "a" << endl;
                    }
                    //delete current;
                }
                else if(p->rchild == current && current->iv.start - p->iv.end == 1)
                {
                    p->iv.end = current->iv.end;
                    //通过旋转来维持BST性质
                    if(current->lchild == NULL && current->rchild == NULL)
                        p->rchild = NULL;
                    else if(current->lchild == NULL && current->rchild != NULL)
                        p->rchild = current->rchild;
                    else if(current->lchild != NULL && current->rchild == NULL)
                        p->rchild = current->lchild;
                    else //左右子节点都存在
                    {
                        p->rchild = current->rchild;

                        Node *q = current->rchild;
                        while(q->lchild != NULL) q = q->lchild;
                        q->lchild = current->lchild;
                        cout << "b" << endl;
                    }
                    //delete current;
                }
                current = p;
            }
        }
    }
    
    vector<Interval> getIntervals() {
        //中序遍历区间
        vector<Interval> result;
        visit(result,this->root);
        for(auto x:result) cout << x.start << "->" << x.end << " ";
        cout << endl;
        return result;
    }

    void visit(vector<Interval>&result,Node *root)
    {
        if(root->lchild != NULL) visit(result,root->lchild);
        result.push_back(root->iv);
        if(root->rchild != NULL) visit(result,root->rchild);
    }

    Node *root;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */

 int main()
 {
     vector<int> test = {1,3,7,2,6};
     SummaryRanges sr;
     for(auto x:test)
     {
        sr.addNum(x);
        sr.getIntervals();
     }
 }



 //修改思路：在插入时就判断，如果可以直接被当前节点吸收，就改变当前节点区间值。如果该值可以把两个节点连接起来，则修改父节点区间值，
 //来合并子节点，然后调整