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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> v;
        if(!root) return v;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int cnt=q.size();
            double sum=0;
            for(int i=0; i<cnt; i++){
                TreeNode *node=q.front();
                q.pop();
                sum+= (double)node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            v.push_back(sum/cnt);
        }
        return v;
    }
};