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
    TreeNode* build(vector<int>& post, int postS, int postE, vector<int>& in, int inS, int inE, map<int,int>& mp){
        if(inS>inE || postS>postE) return NULL;
        TreeNode *node=new TreeNode(post[postS]);
        int ele_idx=mp[node->val];
        int cntright=inE-ele_idx;
        node->right=build(post,postS+1,postS+cntright,in,ele_idx+1,inE,mp);
        node->left=build(post,postS+cntright+1,postE,in,inS,ele_idx-1,mp);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        reverse(post.begin(),post.end());
        map<int,int> mp;
        for(int i=0; i<in.size(); i++) mp[in[i]]=i;
        int postS=0, postE=post.size()-1, inS=0, inE=in.size()-1;
        TreeNode *res=build(post,postS,postE,in,inS,inE,mp);
        return res;
    }
};