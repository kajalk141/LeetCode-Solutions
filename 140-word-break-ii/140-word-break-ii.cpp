class Solution {
    struct trie{
        trie *child[26];
        bool end=0;
    };
    trie *root;
public:
    int n;
    Solution(){
        root=new trie();
    }
    void insert(string s){
        trie *curr=root;
        for(char c:s){
            if(!curr->child[c-'a']) curr->child[c-'a']=new trie();
            curr=curr->child[c-'a'];
        }
        curr->end=1;
    }
    vector<string> res;
    string temp="";
    void search(trie *curr, string s, int idx){
        if(idx==n){
            res.push_back(temp);
            return;
        }
        bool res=false;
        for(int i=idx; i<n; i++){
            if(!curr->child[s[i]-'a']) return;
            curr=curr->child[s[i]-'a'];
            temp+=s[i];
            if(curr->end){
                int len1=temp.size();
                if(i!=n-1) temp+=" ";
                search(root,s,i+1);
                int len2=temp.size();
                while(len2!=len1){
                    temp.pop_back();
                    len2--;
                }
            }
        }
        return;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        n=s.size();
        for(string word:wordDict) insert(word);
        search(root,s,0);
        return res;
    }
};