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
    TreeNode* build(vector<int>& pre, int preS, int preE, vector<int>& in, int inS, int inE, map<int,int>& mp){
        if(inS>inE || preS>preE) return NULL;
        TreeNode *node=new TreeNode(pre[preS]);
        int ele_idx=mp[node->val];
        int cntleft=ele_idx-inS;
        node->left=build(pre,preS+1,preS+cntleft,in,inS,ele_idx-1,mp);
        node->right=build(pre,preS+cntleft+1,preE,in,ele_idx+1,inE,mp);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& pre, vector<int>& in){
        map<int,int> mp;
        for(int i=0; i<in.size(); i++) mp[in[i]]=i;
        int preS=0, preE=pre.size()-1, inS=0, inE=in.size()-1;
        TreeNode *res=build(pre,preS,preE,in,inS,inE,mp);
        return res;
    }
};