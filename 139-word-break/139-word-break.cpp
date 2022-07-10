class Solution {
    struct trie{
        int end=0;
        trie *child[26];
    };
    trie *root;
    int n;
public:
    void insert(string s){
        trie *curr=root;
        for(char c:s){
            if(curr->child[c-'a']==NULL) curr->child[c-'a']=new trie();
            curr=curr->child[c-'a'];
        }
        curr->end++;
    }
            
    bool search(trie *curr, string s, int idx, vector<int> &dp){
        if(idx==n) return true;
        if(dp[idx]!=-1) return dp[idx];
        for(int i=idx; i<n; i++){
            if(!curr->child[s[i]-'a']) return dp[idx]=0;
            curr=curr->child[s[i]-'a'];
            if(curr->end){
                if(search(root,s,i+1,dp)) return dp[idx]=1;
            }
        }
        return dp[idx]=false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        root=new trie();
        n=s.size();
        for(string word:wordDict) 
            insert(word);
        vector<int> dp(n,-1);
        return search(root, s, 0, dp);
    }
};