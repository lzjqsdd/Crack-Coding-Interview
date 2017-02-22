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
    int pathSum(TreeNode* root, int sum) {
        if(root==NULL) return 0;
        target = sum;
        result = 0;
        solve(root,root->val,1);
        return result;
    }
    
    void solve(TreeNode *root,int sum,int depth)
    {
        if(depth>1)
        {
            result++;
            cout << depth << "," << root->val << endl;
        }
        if(root->left!=NULL)
        {
            solve(root->left,sum+root->left->val,depth+1); //包含前置的节点
            solve(root->left,root->left->val,1);
        }
        if(root->right!=NULL)
        {
            solve(root->right,sum+root->right->val,depth+1);
            solve(root->right,root->right->val,1);
        }
    }
    
    int target;
    int result;
};




//递归重复
void solve(TreeNode *root,int sum)
{
    sum -= root->val; //start from root node;
    if(sum == 0) result++;

    if(root->left!=NULL)
    {
        solve(root->left,sum);  //包含当前节点
        solve(root->left,target); //不包含当前节点，从子树重新开始搜索
    }
    if(root->right!=NULL)
    {
        solve(root->right,sum);    
        solve(root->right,target);
    }
}


//采用队列的方式，每次从一个节点开始查找连续的路径。AC
void solve(TreeNode *root,int sum)
{
    sum -= root->val;
    if(sum == 0) result++;
    if(root->left!=NULL)
        solve(root->left,sum);
    if(root->right!=NULL)
        solve(root->right,sum);
}

int main()
{
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode *root = q.front();
        q.pop();
        solve(root);
    }
    return result;
}