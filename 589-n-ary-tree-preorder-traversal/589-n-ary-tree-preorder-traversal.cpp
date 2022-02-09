/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    void dfs(Node* root, vector<int>& v){
        if(!root) return;
        v.push_back(root->val);
        for(auto &child:root->children) dfs(child,v);
    }
public:
    vector<int> preorder(Node* root) {
        vector<int> v;
        dfs(root,v);
        return v;
    }
};