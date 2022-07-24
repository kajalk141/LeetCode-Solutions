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
    vector<vector<int>> paths;
    vector<int> path;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        rec(root,sum);
        return paths;
    }
    
    void rec(TreeNode *root, int sum){
        if(!root) return;
        if(!root->left && !root->right){
            if(sum-root->val==0){
                path.push_back(root->val);
                paths.push_back(path);
                path.pop_back();
            }
            return;
        }
        path.push_back(root->val);
        if(root->left) rec(root->left,sum-root->val);
        if(root->right) rec(root->right,sum-root->val);
        path.pop_back();
    }
};