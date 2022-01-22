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
    int f(TreeNode *root, map<int,int>& mp){
        if(!root) return 0;
        int lsum=f(root->left, mp), rsum=f(root->right, mp);
        int tsum=lsum+rsum+root->val;
        mp[tsum]++;
        return tsum;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        map<int,int> mp;
        f(root, mp);
        int cnt=0;
        for(auto i:mp){
            cnt=max(cnt,i.second);
        }
        vector<int> v;
        for(auto i:mp){
            if(i.second==cnt) v.push_back(i.first);
        }
        return v;
    }
};