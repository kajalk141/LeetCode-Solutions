class WordDictionary {
    struct TrieNode{
        int endOfWord=0;
        TrieNode *child[26];
    };
    
    TrieNode *root;
public:
    WordDictionary() {
        root=new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *curr=root;
        for(char c:word){
            if(curr->child[c-'a']==NULL) curr->child[c-'a']=new TrieNode();
            curr=curr->child[c-'a'];
        }
        curr->endOfWord++;
        return;
    }
    
    bool search(string word) {
        return helper(word, 0, root);
    }
    
    bool helper(string word, int idx, TrieNode *curr){
        int n=word.size();
        for(int i=idx; i<n; i++){
            if(word[i]=='.'){
                for(int j=0; j<26; j++){
                    if(curr->child[j]==NULL) continue;
                    if(helper(word,i+1,curr->child[j])) return true;
                }
                return false;
            }
            else{
                if(curr->child[word[i]-'a']==NULL) return false;
                curr=curr->child[word[i]-'a'];
            }
        }
        return (curr->endOfWord);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */