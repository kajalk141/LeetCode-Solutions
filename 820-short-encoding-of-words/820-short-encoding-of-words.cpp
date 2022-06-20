class Solution {
    struct trie{
        trie *child[26];
    };
    trie *root;
public:
    Solution(){
        root=new trie();
    }
    bool insert(string word){
        trie *temp=root;
        bool res=false;
        for(char c:word){
            if(!temp->child[c-'a']){
                res=true;
                temp->child[c-'a']=new trie();
            }
            temp=temp->child[c-'a'];
        }
        return res;
    }
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), [](string &a, string &b){
            return (int)a.size()>(int)b.size();
        });
        int res=0;
        for(string word:words){
            int n=word.size();
            reverse(word.begin(), word.end());
            if(insert(word)) res+=(n+1);
        }
        return res;
    }
};