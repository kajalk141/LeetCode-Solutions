class Solution {
    struct TrieNode{
        int endOfWord=0;
        TrieNode *child[26];
    };
    TrieNode *root;
public:
    Solution(){
        root=new TrieNode();
    }
    
     void insert(string word) {
        TrieNode *curr=root;
        for(char c:word){
            if(curr->child[c-'a']==NULL){
                curr->child[c-'a']=new TrieNode();
                
            }
            curr=curr->child[c-'a'];
        }
        curr->endOfWord++;
        return;
    }
    
    string prefix(string word){
        TrieNode *curr=root;
        string res="";
        for(char c:word){
            res+=c;
            curr=curr->child[c-'a'];
            if(curr==NULL) return word;
            if(curr->endOfWord>0) return res;
        }
        return word;
    }
    
    string replaceWords(vector<string>& dictionary, string sentence) {
        for(auto word:dictionary){
            insert(word);
        }
        string word="", res="";
        int n=sentence.size();
        for(int i=0; sentence[i]; i++){
            if(sentence[i]!=' ') word+=sentence[i];
            if(sentence[i]==' ' || i==n-1){
                res+=prefix(word);
                res+=" ";
                word="";
            }
        }
        res.pop_back();
        return res;
    }
};