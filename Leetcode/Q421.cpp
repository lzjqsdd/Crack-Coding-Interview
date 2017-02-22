//给定一组数，找出其中两个数，异或的值最大
//前缀树

//异或值最大尽可能使高位不同。异或特点：相同为0，不同为1


class Solution {
public:

    class TreeNode{
        public:
            TreeNode *next[2]; //分别存储节点位0,1。该前缀树为二叉树。左0右1
            TreeNode() {next[0]=NULL;next[1]=NULL;};
    };

    TreeNode * createTree(vector<int> &nums){
        TreeNode *root = new TreeNode(),*cur;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            int num = nums[i];
            cur = root; //遍历每一个二进制位，建立前缀树
            for(int j=31;j>=0;j--){
                int index = ((num >> j) & 1); //每次取最高位
                if(cur->next[index] == NULL)
                    cur->next[index] = new TreeNode();
                cur = cur->next[index];
            }
        }
        return root;
    }

    int helper(TreeNode *cur,int num){
        int res = 0;
        for(int i=31;i>=0;i--){
            int index = ((num >> i) & 1) ? 0:1;
            if(cur->next[index]){ //找与num第i不同的数。如果有就走该分支
                res <<= 1;
                res |= 1; //该位的异或结果为1.
                cur = cur->next[index];
            }else{ //如果没有就沿着该分支走，继续试图找不同。
                res <<= 1;
                res |= 0;
                cur = cur->next[index ? 0:1];
            }
        }
        return res;
    }



    int findMaximumXOR(vector<int>& nums) {
        int res = 0;
        TreeNode *root = createTree(nums);

        for(auto i:nums){
            res = max(res,helper(root,i));
        }
        return res;
    }
};