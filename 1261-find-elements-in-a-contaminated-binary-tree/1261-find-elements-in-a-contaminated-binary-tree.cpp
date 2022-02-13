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
class FindElements {
    void dfs(TreeNode* root, unordered_set<int>& s){
        if(!root) return;
        s.insert(root->val);
        if(root->left) root->left->val=2*root->val+1;
        if(root->right) root->right->val=2*root->val+2;
        dfs(root->left,s);
        dfs(root->right,s);
    }
public:
    unordered_set<int> s;
    FindElements(TreeNode* root) {
        root->val=0;
        dfs(root,s);
    }
    
    bool find(int target) {
        if(s.find(target)==s.end()) return false;
        return true;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */