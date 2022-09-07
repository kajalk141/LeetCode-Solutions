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
    string s;
    void dfs(TreeNode *root, string &s){
        if(!root) return;
        s+= (to_string(root->val));
        if(!root->left && !root->right) return;
        s.push_back('(');
        dfs(root->left,s);
        s.push_back(')');
        if(root->right){
            s.push_back('(');
            dfs(root->right,s);
            s.push_back(')');
        }
    }
    string tree2str(TreeNode* root) {
        s="";
        dfs(root,s);
        return s;
    }
};