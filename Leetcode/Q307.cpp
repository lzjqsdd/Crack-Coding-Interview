//题意：给定一个数组，计算[i,j]元素之和。update(i,val)会更新位置i的值
//思路：如果每次按照遍历i到j去计算的话，则如果高频更新元素的值则复杂度很高
//采用线段树

struct SegmentTreeNode{
    int start,end,sum;
    SegmentTreeNode* left;
    SegmentTreeNode* right;
    SegmentTreeNode(int a,int b):
        start(a),
        end(b),
        sum(0),
        left(nullptr),
        right(nullptr)
        {}
};

class NumArray
{
    SegmentTreeNode* root;
public:
    NumArray(vector<int> &nums){
        int n = nums.size();
        root = buildTree(nums,0,n-1);
    }

    void update(int i,int val){
        modifyTree(i,val ,root);
    }

    int sumRange(int i,int j)
    {
        return queryTree(i,j,root);
    }

    SegmentTreeNode *buildTree(vector<int>& nums,int start,int end){
        if(start > end) return nullptr; //特别主要异常情况的处理
        SegmentTreeNode *root = new SegmentTreeNode(start,end);
        if(start == end){
            root->sum = nums[start];
            return root;
        }
        int mid = start + (end - start)/2;
        root->left = buildTree(nums,start,mid);
        root->right = buildTree(nums,mid+1,end);
        root->sum = root->left->sum + root->right->sum;
        return root;
    }

    int modifyTree(int i,int val ,SegmentTreeNode* root)
    {
        if(root == nullptr) return 0;
        int diff;
        if(root->start == i && root->end == i){
            diff = val - root->sum;
            root->sum = val;
            return diff;
        }
        int mid = (root->start + root->end)/2;
        if(i > mid)
        {
            diff = modifyTree(i,val,root->right);
        }
        else
            diff = modifyTree(i,val, root->left);
        root->sum = root->sum + diff;
        return diff;
    }
    int queryTree(int i,int j,SegmentTreeNode* root){
        if(root == nullptr) return 0;
        if(root->start == i && root->end == j) return root->sum; //区间和已经有了则直接返回
        int mid = (root->start + root->end) / 2;
        if(i > mid) return queryTree(i,j,root->right);
        if(j <= mid) return queryTree(i,j,root->left);
        return queryTree(i,mid,root->left) + queryTree(mid+1,j,root->right);
    }
}；