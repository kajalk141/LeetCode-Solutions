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
    int sum(TreeNode *root, int& res){
        if(!root) return 0;
        int l=sum(root->left, res);
        int r=sum(root->right, res);
        l=max(l,0);
        r=max(r,0);
        res=max(res, root->val+l+r);
        return root->val+max(l,r);
    }
public:
    int maxPathSum(TreeNode* root) {
        int res=INT_MIN;
        sum(root,res);
        return res;
    }
};