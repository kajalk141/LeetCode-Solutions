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
    bool check(TreeNode *lefts, TreeNode *rights){
        if(!lefts && !rights) return 1;
        if(!lefts || !rights) return 0;
        return (lefts->val==rights->val && check(lefts->left, rights->right) && check(lefts->right, rights->left));
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return 1;
        return check(root->left, root->right);
    }
};