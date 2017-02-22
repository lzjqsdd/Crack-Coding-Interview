//124. Binary Tree Maximum Path Sum

//因为结果可能同时包含左右子树，为判断是否加入左右子树，采用自底向上的方式。
//题目的意思任意联通的路径，可以从左子树到右子树的路径
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
    int maxPathSum(TreeNode* root) {
        result = INT_MIN;
        solve(root);
        return result;
    }
    int result;
    int solve(TreeNode * root) //sum表示到当前root节点时的总和（从某个点开始到该节点，可以看作该节点的新值）
    {
        if(root==NULL) return 0;
        int l = solve(root->left);
        int r = solve(root->right);
        int s = l + r;
        int sum = root->val;
        if(l <=0 && r<=0)
        {
            if(result < sum) result = sum;
            return sum;
        }
        else
        {
            if(l > 0 && r > 0) sum+=s;
            else sum+=max(l,r);
            if(result < sum) result = sum;
            return root->val+max(l,r);
        }
    }
};


[1,2,3]
[-5,0,0]
[3,6,8,-10,3,5,3,null,6,-7,null,null,10,-21]
[3,5,3,null,6,-7,null,null,10,5,3,2,null,4,null,1,34,0,0,null,34,0,0,0,1,43,34,9,0,8,0]
[0,0,0,-1,0,0]
[1,-2,3]