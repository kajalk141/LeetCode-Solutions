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
class BSTIterator {
public:
    vector<int> v;
    int i=-1, n;
    void dfs(TreeNode *root){
        if(!root) return;
        dfs(root->left);
        v.push_back(root->val);
        dfs(root->right);
    }
    BSTIterator(TreeNode* root) {
        dfs(root);
        n=v.size();
    }
    
    int next() {
        return v[++i];
    }
    
    bool hasNext() {
        return (i==n-1?0:1);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */