//Path Sum II

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root == NULL) return {};
        vector<int> path;
        solve(root,path,sum);
        return result;
    }
    
    void solve(TreeNode *root,vector<int>& path,long sum)
    {
        path.push_back(root->val); sum-= root->val;
        if(root->left == NULL && root->right==NULL)
        {
            if(sum == 0) result.push_back(path);
        }
        if(root->left!=NULL)
            solve(root->left,path,sum);
        if(root->right!=NULL)
            solve(root->right,path,sum);
        
        sum+=root->val; path.erase(path.end()-1);
            
    }
    
    vector<vector<int> > result;
};