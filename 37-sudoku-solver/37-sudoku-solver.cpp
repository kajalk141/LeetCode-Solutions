class Solution {
public:
    bool  row[9][10]={0}, col[9][10]={0}, sq[9][10]={0};
    void solveSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]!='.'){
                    int num=board[i][j]-'0', square=(i/3)*3 + j/3;
                    row[i][num]=1;
                    col[j][num]=1;
                    sq[square][num]=1;
                }
            }
        }
        rec(0,0,board);
        return;
    }
    
    bool rec(int i, int j, vector<vector<char>>& board){
        if(i==9 || j==9) return true;
        if(board[i][j]!='.'){
            if(j==8) return rec(i+1, 0, board);
            else return rec(i, j+1, board);
        }
        int square=(i/3)*3 + j/3;
        for(char num=1; num<=9; num++){
            if(row[i][num]==0 && col[j][num]==0 && sq[square][num]==0){
                board[i][j]=num+'0';
                row[i][num]=1; col[j][num]=1; sq[square][num]=1;
                if(j==8 && rec(i+1,0,board)) return true;
                if(j<8 && rec(i,j+1,board)) return true;
                row[i][num]=0; col[j][num]=0; sq[square][num]=0;
                board[i][j]='.';
            }
        }
        return false;
    }
};