//zigzag层序遍历tree
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<pair<TreeNode*,int>> fq; //正向
        queue<pair<TreeNode*,int>> bq; //逆向
        fq.push(make_pair(root,0));
        bq.push(make_pair(root,0));
        int level = 0;
        vector<vector<int>> result;
        vector<int> ele;
        while(!fq.empty())
        {
            pair<TreeNode*,int> fp = fq.front(); fq.pop();
            pair<TreeNode*,int> bp = bq.front(); bq.pop();
            if(level!=fp.second)
            {
                level = fp.second;
                result.push_back(ele);
                ele.clear();
            }
            if(fp.second%2 == 0)
                ele.push_back(fp.first->val);
            else
                ele.push_back(bp.first->val);

            if(fp.first->left!=NULL) fq.push(make_pair(fp.first->left,level+1));
            if(fp.first->right!=NULL) fq.push(make_pair(fp.first->right,level+1));
            if(bp.first->right!=NULL) bq.push(make_pair(bp.first->right,level+1));
            if(bp.first->left!=NULL) bq.push(make_pair(bp.first->left,level+1));
        }
        if(!ele.empty()) result.push_back(ele);
        return result;
    }
};