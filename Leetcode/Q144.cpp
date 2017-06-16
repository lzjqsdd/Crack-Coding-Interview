/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> result;
        inorder(root,result);
        return result;
    }

    void inorder(TreeNode*root,vector<int>&result)
    {
        if(root != NULL)
        {
            result.push_back(root->val);
            inorder(root->left,result);
            inorder(root->right,result);
        }
    }
};


//非递归方法，借助外部的栈
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode *> s;
        TreeNode *cur = root;
        while(!s.empty() || cur)
        {
            if(cur) //不断深度遍历左子树
            {
                result.push_back(cur->val);
                s.push(cur); //压栈
                cur = cur->left;
            }
            else
            {
                cur = s.top();
                s.pop();
                cur = cur->right;
            }
        }
        return result;
    }
};