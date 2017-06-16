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
        if(root == NULL){
            root = new Node(iv); //建立根
            return;
        }
        Node *node = new Node(iv); //待插入
        Node *current = root;
        while(current) //插入节点同时判断是否可以加入已有区间
        {
            if(val < current->iv.start)
            {
                if(current->iv.start -  val == 1) //如果可以直接连起来
                {
                    current->iv.start = val; current = current->lchild; break;
                }
                else
                {
                    if(current->lchild != NULL) current = current->lchild;
                    else {current->lchild = node; node->parent = current; current = current->lchild; break;}
                }
            }
            else if(val > current->iv.end)
            {
                if(val - current->iv.end == 1)
                {
                    current->iv.end = val; current = current->rchild; break;
                }
                else
                {
                    if(current->rchild != NULL) current = current->rchild;
                    else {current->rchild = node; node->parent = current; current = current->rchild; break;}
                }
            }
            else return; //存在在已有区间
        }

        //自下而上合并，合并起点是上一步中如果发生变动的区间的子节点。
        while(current!= NULL && current->parent != NULL)
        {
            Node *p = current->parent;
            if(p->lchild == current && p->iv.start - current->iv.end == 1) //左子树可合并进来
            {
                p->iv.start = current->iv.start; //合并，接下来删除被合并的节点
                //通过旋转来维持BST性质
                if(current->lchild == NULL && current->rchild == NULL)
                    p->lchild = NULL;
                else if(current->lchild == NULL && current->rchild != NULL)
                {   p->lchild = current->rchild; current->rchild->parent = p;}
                else if(current->lchild != NULL && current->rchild == NULL)
                {   p->lchild = current->lchild; current->lchild->parent = p;}
                else //左右子节点都存在
                {
                    p->lchild = current->rchild; current->rchild->parent = p;
                    Node *q = current->rchild;
                    while(q->lchild != NULL) q = q->lchild;
                    q->lchild = current->lchild; current->lchild->parent = q;
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
                {    p->rchild = current->rchild;  current->rchild->parent = p;  }
                else if(current->lchild != NULL && current->rchild == NULL)
                {    p->rchild = current->lchild;  current->lchild->parent = p;  }
                else //左右子节点都存在
                {
                    p->rchild = current->rchild; current->rchild->parent = p;
                    Node *q = current->rchild;
                    while(q->lchild != NULL) q = q->lchild;
                    q->lchild = current->lchild; current->lchild->parent = q;
                }
                //delete current;
            }
            current = p;
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
        if(result.size() > 0 && (result.back().end - root->iv.start == -1 || result.back().end == root->iv.start))
        {
            result.back().end = root->iv.end;
        }
        else
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
     //vector<int> test = {1,3,7,2,6,4,8,9,10,13,12,11,5,-1,0,20,24,34,25};
     vector<int> test = {6,6,0,4,8,7,6,4,7,5};
     SummaryRanges sr;
     for(auto x:test)
     {
        sr.addNum(x);
        sr.getIntervals();
     }
 }



 //修改思路：在插入时就判断，如果可以直接被当前节点吸收，就改变当前节点区间值。如果该值可以把两个节点连接起来，则修改父节点区间值，
 //来合并子节点，然后调整


///////lvzejun!!!!//
//c++ set底层为红黑树平衡的二叉搜索树
//lower_bound返回在有序序列中不小于value的第一个迭代器的位置
//能用STL尽量使用STL中的函数
//比如make_heap建堆 http://www.cplusplus.com/reference/algorithm/sort_heap/
 class SummaryRanges {
public:
    /** Initialize your data structure here. */
    void addNum(int val) {
        auto it = st.lower_bound(Interval(val, val));
        int start = val, end = val;
        if(it != st.begin() && (--it)->end+1 < val) it++;
        while(it != st.end() && val+1 >= it->start && val-1 <= it->end)
        {
            start = min(start, it->start);
            end = max(end, it->end);
            it = st.erase(it);
        }
        st.insert(it,Interval(start, end));
    }
    
    vector<Interval> getIntervals() {
        vector<Interval> result;
        for(auto val: st) result.push_back(val);
        return result;
    }
private:
    struct Cmp{
        bool operator()(Interval a, Interval b){ return a.start < b.start; }
    };
    set<Interval, Cmp> st;
};