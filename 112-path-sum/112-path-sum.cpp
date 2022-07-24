/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        if(!root->left && !root->right){
            if(sum-root->val==0) return 1;
            return 0;
        }
        bool res=0;
        if(root->left) res=res||hasPathSum(root->left,sum-root->val);
        if(root->right) res=res||hasPathSum(root->right,sum-root->val);
        return res;
    }
};