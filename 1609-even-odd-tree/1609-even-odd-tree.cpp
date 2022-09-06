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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int l=0;
        while(!q.empty()){
            vector<int> level;
            int cnt=q.size();
            for(int i=0; i<cnt; i++){
                TreeNode *node=q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(l%2==1) reverse(level.begin(), level.end());
            for(int i=0; i<cnt; i++){
                if((l%2)==(level[i]%2)) 
                    return 0;
                if(i>0 && level[i-1]>=level[i])
                    return 0;
            }
            l++;
        }
        return 1;
    }
};