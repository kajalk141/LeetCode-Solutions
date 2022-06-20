int m,n;
class Solution {
    struct trie{
        trie *child[26];
        int end=0;
        string word="";
    };
    trie *root;
public:
    vector<string> res;
    Solution(){
        root=new trie();
    }
    void insert(string s){
        trie *temp=root;
        for(char c:s){
            if(!temp->child[c-'a']) temp->child[c-'a']=new trie();
            temp=temp->child[c-'a'];
        }
        temp->end++;
        temp->word=s;
    }
    bool check(int i, int j, vector<vector<char>>& board, trie *curr){
        if(i<0||i>=m||j<0||j>=n||board[i][j]=='.') return false;
        if(!curr->child[board[i][j]-'a']) return false;
        return true;
    }
    void rec(int i, int j, vector<vector<char>>& board, trie *curr){
        // if(curr->child[board[i][j]-'a']==NULL) return;
        // curr=curr->child[board[i][j]-'a'];
        if(curr->end){
            res.push_back(curr->word);
            curr->end--;
        }
        char temp=board[i][j];
        board[i][j]='.';
        if(check(i+1,j,board,curr)) rec(i+1,j,board,curr->child[board[i+1][j]-'a']);
        if(check(i-1,j,board,curr)) rec(i-1,j,board,curr->child[board[i-1][j]-'a']);
        if(check(i,j+1,board,curr)) rec(i,j+1,board,curr->child[board[i][j+1]-'a']);
        if(check(i,j-1,board,curr)) rec(i,j-1,board,curr->child[board[i][j-1]-'a']);
        board[i][j]=temp;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        res.clear();
        for(string word:words) insert(word);
        m=board.size(); n=board[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(root->child[board[i][j]-'a']!=NULL)
                rec(i,j,board,root->child[board[i][j]-'a']);
            }
        }
        return res;
    }
};