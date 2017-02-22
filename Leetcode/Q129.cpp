//Sum Root to Leaf Numbers
//每个从root到leaf的路径表示一个数，求这些数的和
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
    int sumNumbers(TreeNode* root) {
        if(root==NULL) return 0;
        result = 0;
        solve(root,0);
        return result;
    }
    int result;
    void solve(TreeNode *root,int sum)
    {
        sum = sum*10+root->val;
        if(root->left==NULL && root->right == NULL){
            result += sum;
            return;
        }
        if(root->left!=NULL) solve(root->left,sum);
        if(root->right!=NULL) solve(root->right,sum);
    }
};