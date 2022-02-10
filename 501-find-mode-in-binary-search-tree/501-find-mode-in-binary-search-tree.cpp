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
    void dfs(TreeNode* root, map<int,int>& mp){
       if(!root) return;
        mp[root->val]++;
        dfs(root->left, mp);
        dfs(root->right, mp);
    }
public:
    vector<int> findMode(TreeNode* root) {
        map<int,int> mp;
        dfs(root,mp);
        vector<int> v;
        int res=0;
        for(auto i:mp){
            if(i.second>res){
                res=i.second;
                v.clear();
                v.push_back(i.first);
            }
            else if(i.second==res){
                v.push_back(i.first);
            }
        }
        return v;
        
    }
};