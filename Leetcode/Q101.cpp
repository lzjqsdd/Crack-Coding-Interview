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
    bool isSymmetric(TreeNode* root) {
        return solve(root,root);
    }
    
    bool solve(TreeNode *froot,TreeNode *broot) //左中右，右中左
    {
        if(froot!=NULL && broot!=NULL)
        {
            if(froot->val != broot->val) return false;
            else
            {
                return solve(froot->left,broot->right) && solve(froot->right,broot->left);
            }
        }
        else if((froot==NULL && broot!=NULL) || (froot!=NULL && broot==NULL)) //一个为空，一个不为空，不对称
            return false;
        return true;
    }
};