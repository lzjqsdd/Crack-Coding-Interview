//题意：根据中序遍历和先序遍历还原二叉树
//思路：由先序遍历(preOrder)来确定(inorder)的划分，先序遍历的值为root
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0) return NULL;
        TreeNode *root;
        buildBT(preorder,0,inorder,0,inorder.size()-1,root);
        return root;
    }

    void buildBT(vector<int>&preorder,int &k,vector<int>&inorder,int i,int j,TreeNode* &root) //i,j表示子树所处的范围.k表示当前划分的根在preorder的位置
    {
        if(i > j) return;
        root = new TreeNode(0);
        root->val = preorder[k]; //先加入根节点

        int pivot = find(inorder.begin(),inorder.end(),preorder[k]) - inorder.begin();
        if(i < pivot) //如果有左子树
            buildBT(preorder,++k,inorder,i,pivot-1,root->left);
        if(j > pivot) //如果有右子树
            buildBT(preorder,++k,inorder,pivot+1,j,root->right);
    }
};



int main()
{
    vector<int> preorder = {1,2,4,5,6,7,3,8};
    vector<int> inorder = {4,2,6,5,7,1,3,8};
    Solution s;
    s.buildTree(preorder,inorder);
}

/*
[4,2,6,5,7,1,3,8]
[1,2,4,5,6,7,3,8]

[4,2,6,5,7,-1-,3,8]
[4,-2-,6,5,7]
[-4-]
[6,-5-,7]
[6]
[7]
[-3-,8]
[-8-]
*/