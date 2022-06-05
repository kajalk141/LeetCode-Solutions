int dx[]={-2,-1,1,2};
int dy[]={-2,-1,1,2};
class Solution {
    double rec(int i, int j, int k, int n, vector<vector<vector<double>>> &dp){
        if(i<0||j<0||i>=n||j>=n) return 0;
        if(k==0) return 1;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        double in=0;
        for(int x=0; x<4; x++){
            for(int y=0; y<4; y++){
                if(abs(dx[x])==abs(dy[y])) continue;
                in+=0.125*rec(i+dx[x],j+dy[y],k-1,n,dp);
            }
        }
        return dp[i][j][k]=in;
        
    }
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n,vector<vector<double>>(n,vector<double>(k+1,-1)));
        return rec(row,column,k,n,dp);
       
    }
};