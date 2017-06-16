//题意：生成1~n的数可能组成的左右的BST
//思路: 递归+分治，递归中每次选择一个数作为root，然后递归构建更小的BST
//当只有一个数时，只有一种情况，当有两个数时，每个树都可以作为root，注意划分点root左侧的数位左子树，右侧的数为右子树。


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//starttime :14.10
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return DandC(1,n); //[1,n]
    }
    
    vector<TreeNode*> DandC(int l,int r)
    {
        if(l == r) return vector<TreeNode*>(1,new TreeNode(l));
        else
        {
            vector<TreeNode*> res;
            for(int i=l;i<=r;++i)
            {
                vector<TreeNode*> lres;
                vector<TreeNode*> rres;
                if(i-1>=1) lres = DandC(l,i-1); //左子树BST
                if(i+1<=r) rres = DandC(i+1,r); //右子树BST
                if(lres.size()==0 && rres.size()>0) //只有右子树
                {
                    for(auto x:rres)
                    {
                        TreeNode*root = new TreeNode(i);
                        root->right = x;
                        res.push_back(root);
                    }
                }
                else if(lres.size() > 0  && rres.size() == 0)
                {
                    for(auto x:lres)
                    {
                        TreeNode *root = new TreeNode(i);
                        root->left = x;
                        res.push_back(root);
                    }
                }
                else //同时为0已经被l==r处理掉了
                {
                    for(auto l:lres)
                        for(auto r:rres)
                        {
                            TreeNode *root = new TreeNode(i);
                            root->left = l; root->right = r;
                            res.push_back(root);
                        }
                }

            }
            return res;
        }
    }
};