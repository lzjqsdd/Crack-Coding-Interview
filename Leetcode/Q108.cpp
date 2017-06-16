//题意：给定一个数组，升序排列，把它转换成一个平衡的BST
//思路：因为需要平衡的BST,而原有序列为有序，所以很朴素的想法，把原有序列等分，然后作为根节点。
//因为原序列位链表，所以查找中点的代价为O(n),而二分建树需要O(logn),所有总复杂度为O(nlogn)

//二分每次指定要分的长度，以及起始的位置。

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        if(nums.size() == 0) return NULL;
        TreeNode *root = NULL;
        buildTree(nums,0,nums.size()-1,root); //传递的应该按照下标顺序，r-1,而不是r
        return root;
    }

    void buildTree(vector<int>& nums,int l,int r,TreeNode *&root)
    {
        if(l <= r)
        {
            int mid = l+(r - l +1 )/2; //让中点偏右，(r-l)/2让中点偏左。
            root = new TreeNode(0);
            root->val = nums[mid];
            buildTree(nums,l,mid-1,root->left);
            buildTree(nums,mid+1,r,root->right);
        }
    }
};