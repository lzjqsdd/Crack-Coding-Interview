#include <iostream>
#include <string>
#include <vector>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
   vector<string> binaryTreePaths(TreeNode* root) {
        //string s;
        result.clear();
        solve(root,"");
        return result;
    }
    
    vector<string> result;
    void solve(TreeNode *root,string s)
    {
        if(root==NULL) return;
        s.insert(s.size()-1,1,root->val);
        if(root->left==NULL && root->right == NULL)
        {
            cout<<s<<endl;
            result.push_back(s);
        }
        solve(root->left,s);
        solve(root->right,s);
    }
};