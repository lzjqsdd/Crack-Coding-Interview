//输出从二叉树右侧看到的节点
/*
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 //层序遍历，输出每层最右侧的值
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
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL) return {};
        queue<pair<TreeNode*,int>> q;
        vector<int> result;
        q.push(make_pair(root,0));
        int lev = -1; //每次加入队列先加右侧的再加左侧，如果队列元素的level不同，说明是下一层的最右侧
        while(!q.empty())
        {
            pair<TreeNode *,int> tmp = q.front();
            q.pop();
            if(lev != tmp.second)
            {
                result.push_back(tmp.first->val);
                lev = tmp.second;
            }
            if(tmp.first->right!=NULL) q.push(make_pair(tmp.first->right,tmp.second+1));
            if(tmp.first->left!=NULL) q.push(make_pair(tmp.first->left,tmp.second+1));
        }
        return result;

    }
};