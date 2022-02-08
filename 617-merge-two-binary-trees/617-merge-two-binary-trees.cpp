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
    TreeNode* create(TreeNode *root1, TreeNode *root2){
        if(!root1 && !root2) return NULL;
        int sum=0;
        if(root1) sum+=root1->val;
        if(root2) sum+=root2->val;
        TreeNode *root=new TreeNode();
        root->val=sum;
        root->left=create(root1?root1->left:root1, root2?root2->left:root2);
        root->right=create(root1?root1->right:root1, root2?root2->right:root2);
        return root;
    }
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode *res=create(root1,root2);
        return res;
    }
};