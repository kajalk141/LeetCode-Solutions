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
/*
2->camera installed and is monitored
1->no camera but monitored
0->no camera and not being monitored
*/
class Solution {
    int rec(TreeNode *root){
        if(!root) return 1;
        int l=rec(root->left), r=rec(root->right);
        if(l==0||r==0){
            ans++;
            return 2;
        }
        if(l==2||r==2) return 1;
        return 0;
    }
public:
    int ans=0;
    int minCameraCover(TreeNode* root) {
        if(rec(root)==0) ans++;
        return ans;
    }
};