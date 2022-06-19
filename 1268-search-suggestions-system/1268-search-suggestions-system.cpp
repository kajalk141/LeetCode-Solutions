class Solution {
    struct trie{
        trie *child[26];
        int end=0;
        vector<string> v;
    };
    trie *root;
public:
    Solution(){
        root=new trie();
        for(int i=0; i<26; i++) root->child[i]=NULL;
    }
    void insert(string word){
        trie *temp=root;
        for(char c:word){
            if(temp->child[c-'a']==NULL) temp->child[c-'a']=new trie();
            temp=temp->child[c-'a'];
            if((int)temp->v.size()<3)
                temp->v.push_back(word);
        }
        temp->end=1;
    }
    void search(string &s, vector<string> &t){
        trie *temp=root;
        for(char c:s){
            if(!temp->child[c-'a']) return;
            temp=temp->child[c-'a'];
        }
        int i=temp->v.size();
        int j=0;
        while(j<i){
            t.push_back(temp->v[j]);
            j++;
        }
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        for(string word:products) insert(word);
        string s="";
        vector<vector<string>> res;
        for(char c:searchWord){
            s+=c;
            vector<string> t;
            search(s,t);
            res.push_back(t);
        }
        return res;
    }
};