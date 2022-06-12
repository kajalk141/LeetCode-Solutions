class Solution {
    struct TrieNode{
        TrieNode *child[10];
        int end=0;
    };
    TrieNode *root;
public:
    vector<int> res;
    
    Solution(){
        root=new TrieNode();
    }
    void insert(string s){
        TrieNode *curr=root;
        for(char c:s){
            if(curr->child[c-'0']==NULL) curr->child[c-'0']=new TrieNode();
            curr=curr->child[c-'0'];
        }
        curr->end++;
    }
    
    void search(TrieNode *curr, string &s){
        for(int i=0; i<10; i++){
            if(!curr->child[i]) continue;
            s=s+ to_string(i);
            if(curr->child[i]->end>0) res.push_back(stoi(s));
            search(curr->child[i], s);
            s.pop_back();
        }
    }
    vector<int> lexicalOrder(int n) {
        for(int i=1; i<=n; i++){
            string s=to_string(i);
            insert(s);
        }
        string s="";
        search(root,s);
        return res;
    }
};