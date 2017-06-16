//给定二叉树，求其Tilt,Tile表示两个子数sum之差的绝对值，求这棵树所有节点的Tilt之和

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
    int findTilt(TreeNode* root) {
        int result = 0;
    }

    int sovle(TreeNode* root,int &result)
    {
        int left = 0,right = 0;
        if(root->left != NULL) left = solve(root->left,result);
        if(root->right!= NULL) right = solve(root->right,result);
        result += abs(left - right)
        return root->val+left+right; //返回的是子树的和
    }
};