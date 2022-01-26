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
    int widthOfBinaryTree(TreeNode* root) {
        int res=0;
        queue<pair<TreeNode*, int>> q;
        q.push({root,0});
        while(!q.empty()){
            int l, r, cnt=q.size(), curmin=q.front().second;
            for(int i=0; i<cnt; i++){
                TreeNode *node=q.front().first;
                int curid=q.front().second-curmin;
                if(i==0) l=curid;
                if(i==cnt-1) r=curid;
                q.pop();
                if(node->left) q.push({node->left, 2*(curid)+1});
                if(node->right) q.push({node->right, 2*(curid)+2});
            }
            res=max(res, (r-l+1));
        }
        return res;
    }
};