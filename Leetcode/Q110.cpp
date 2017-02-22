//判断一个树是不是平衡二叉树
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
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        int i=0;
        return solve(root,i);
    }
    
    //判断每个节点的子数是不是平衡树
    bool solve(TreeNode *root,int &i)
    {
        if(root==NULL) 
        { i = 0;return true;} //叶节点看做空数，平衡
        
        int ld,rd; //子树从0开始计算
        bool lt = solve(root->left,ld);
        bool rt = solve(root->right,rd);
        cout << ld << "," << rd << endl;
        if(lt && rt)
        {
            int x = abs(ld-rd);
            if(x > 1) return false;
            else
            {
                i = 1+(ld > rd ? ld:rd); //如果子树平衡，递归上一层，记录上一层子树（左/右）最长的长度。
                return true;
            }
        }
        return false;
    }
};