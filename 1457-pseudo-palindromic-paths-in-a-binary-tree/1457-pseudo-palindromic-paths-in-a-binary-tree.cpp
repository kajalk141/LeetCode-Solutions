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
    unordered_map<int,int> mp;
    int res=0;
    void dfs(TreeNode *root){
        if(!root) return;
        mp[root->val]++;
        if(!root->left && !root->right){
            int odd=0;
            for(auto x:mp){
                odd+= (x.second%2);
            }
            res=(odd<=1?res+1:res);
            mp[root->val]--;
            return;
        }
        dfs(root->left);
        dfs(root->right);
        mp[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        dfs(root);
        return res;
    }
};