class trie{
public:
    trie *child[27];
    int mx_idx=-1;
};
class WordFilter {
    trie *root=new trie();
public:
    void insert(string &word, int i){
        int n=word.size();
        for(int j=0; j<n; j++){
            string s=word.substr(j);
            trie *temp=root;
            for(char c:s){
                if(temp->child[c-'a']==NULL) temp->child[c-'a']=new trie();
                temp=temp->child[c-'a'];
            }
            if(!temp->child[26]) temp->child[26]=new trie();
            temp=temp->child[26];
            for(char c:word){
                if(!temp->child[c-'a']) temp->child[c-'a']=new trie();
                temp=temp->child[c-'a'];
                temp->mx_idx=max(temp->mx_idx,i);
            }  
        }
    }
    WordFilter(vector<string>& words) {
        int n=words.size();
        for(int i=0; i<n; i++){
            insert(words[i],i);
        }
    }
    int f(string prefix, string suffix) {
        trie *temp=root;
        for(char c:suffix){
            if(!temp->child[c-'a']) return -1;
            temp=temp->child[c-'a'];
        }
        if(!temp->child[26]) return -1;
        temp=temp->child[26];
        for(char c:prefix){
            if(!temp->child[c-'a']) return -1;
            temp=temp->child[c-'a'];
        }
        return temp->mx_idx;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */