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
    TreeNode* f(vector<int>& nums, int start, int end){
        if(start>end || start<0 || end>=nums.size()) return NULL;
        int idx=(start+end)/2;
        TreeNode *root=new TreeNode(nums[idx]);
        root->left=f(nums,start,idx-1);
        root->right=f(nums,idx+1,end);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode *root=f(nums,0,nums.size()-1);
        return root;
    }
};