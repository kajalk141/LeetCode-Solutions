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
    vector<int> val;
    void rec(TreeNode *root){
        if(!root) return;
        rec(root->left);
        val.push_back(root->val);
        rec(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        rec(root);
        int res=INT_MAX;
        for(int i=1; i<(int)val.size(); i++) 
            res=min(res,val[i]-val[i-1]);
        return res;
    }
};