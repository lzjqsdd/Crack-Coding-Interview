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
    int countNodes(TreeNode* root) {
        return solve(root,1);
    }

    int solve(TreeNode *root,int no)
    {
        int ld = depthFirst(root->left);
        int rd = depthFirst(root->right);
        if(ld == 0 && rd == 0) //说明二分查找递归到终止点了
        {
            return no;
        }
        if(ld  == rd) //说明终止点在右子树上
            return solve(root->right,2*no+1);
        else if(ld > rd) //终止点在左子树上
            return solve(root->left,2*no); 
        
        return 0;
    }

    int depthFirst(TreeNode *root) //左子树深度遍历
    {
        int i = 0;
        while(root!=NULL)
        {
            root = root->left;
            i++;
        }
        return i;
    }

    int result;
};