int n,m;
class Solution {
    bool rec(int x, int y, vector<vector<char>> &board, string word, int idx){
        if(word[idx]=='\0') return true;
        if(x<0||x>=n||y<0||y>=m) return false;
        if(word[idx]!=board[x][y]) return false;
        bool res=false;
        char org=board[x][y];
        board[x][y]='.';
        res=res||rec(x-1,y,board,word,idx+1);
        res=res||rec(x+1,y,board,word,idx+1);
        res=res||rec(x,y-1,board,word,idx+1);
        res=res||rec(x,y+1,board,word,idx+1);
        if(!res) board[x][y]=org;
        return res;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        n=board.size();
        m=board[0].size();
        bool res=false;
        for(int x=0; x<n; x++){
            for(int y=0; y<m; y++){
                if(word[0]==board[x][y]){
                    char org=board[x][y];
                    board[x][y]='.';
                    res=res||rec(x-1,y,board,word,1);
                    res=res||rec(x+1,y,board,word,1);
                    res=res||rec(x,y-1,board,word,1);
                    res=res||rec(x,y+1,board,word,1);
                    if(!res) board[x][y]=org;
                }
            }
        }
        return res;
    }
};