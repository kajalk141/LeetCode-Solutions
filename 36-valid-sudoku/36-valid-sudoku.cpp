class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<int, set<int>> col, row, sq;
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]=='.') continue;
                int num=board[i][j]-'0';
                if(row[num].find(i)!=row[num].end()) return false;
                if(col[num].find(j)!=col[num].end()) return false;
                int square;
                if(i>=0 && i<=2){
                    if(j>=0 && j<=2) square=1;
                    else if(j>=3 && j<=5) square=2;
                    else square=3;
                }
                else if(i>=3 && i<=5){
                    if(j>=0 && j<=2) square=4;
                    else if(j>=3 && j<=5) square=5;
                    else square=6;
                }
                else{
                    if(j>=0 && j<=2) square=7;
                    else if(j>=3 && j<=5) square=8;
                    else square=9;
                }
                if(sq[num].find(square)!=sq[num].end()) return false;
                row[num].insert(i);
                col[num].insert(j);
                sq[num].insert(square);
            }
        }
        return true;
    }
};