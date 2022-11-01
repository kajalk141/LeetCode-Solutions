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
typedef pair<int,int> pii;
class Solution {
public:
    unordered_map<int, vector<int>> cousins;
    unordered_map<int, int> height;
    unordered_map<int, int> depth;
    
    int dfs(TreeNode *root){
        if(!root) return 0;
        if(!root->left && !root->right) return height[root->val]=0;
        int l=dfs(root->left), r=dfs(root->right);
        return height[root->val]=max(l,r)+1;
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        dfs(root);
        queue<TreeNode*> q;
        if(root) q.push(root);
        int d=0;
        while(!q.empty()){
            int sz=q.size();
            int first=-1, second=-1;
            for(int i=0; i<sz; i++){
                TreeNode *node=q.front();
                q.pop();
                depth[node->val]=d;
                if(height[node->val]>first){    
                    second=first;
                    first=height[node->val];
                }
                else if(height[node->val]>second){
                    second=height[node->val];
                }
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            cousins[d].push_back(first);
            if(second!=-1) cousins[d].push_back(second);
            d++;
        }
        vector<int> res;
        for(int &q:queries){
            int dep=depth[q];
            if(cousins[dep][0]!=height[q]) res.push_back(height[root->val]);
            else{
                if((int)cousins[dep].size()==1) res.push_back(dep-1);
                else res.push_back(dep+cousins[dep][1]);
            }
        }
        return res;
    }
};