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
    vector<string> res;
    vector<string> binaryTreePaths(TreeNode* root) {
        string curr="";
        curr+= to_string(root->val);
        dfs(root,curr);
        return res;
    }
    
    void dfs(TreeNode *root, string curr){
        if(!root->left && !root->right){
            res.push_back(curr);
            return;
        }
        if(root->left) dfs(root->left, curr+"->"+to_string(root->left->val));
        if(root->right) dfs(root->right, curr+"->"+to_string(root->right->val));
    }
};