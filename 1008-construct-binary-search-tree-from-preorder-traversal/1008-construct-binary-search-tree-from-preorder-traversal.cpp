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
    TreeNode* construct(vector<int>& pre, int start, int end){
        if(start>end || start<0 || end>=pre.size()) return NULL;
        TreeNode *root=new TreeNode(pre[start]);
        //if(start==end) return root;
        int idx=end;
        for(int i=start+1; i<=end; i++){
            if(pre[i]>pre[start]){
                idx=i-1;
                break;
            }
        }
        root->left=construct(pre,start+1,idx);
        root->right=construct(pre,idx+1,end);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& pre) {
        TreeNode *root=construct(pre,0,pre.size()-1);
        return root;
    }
};