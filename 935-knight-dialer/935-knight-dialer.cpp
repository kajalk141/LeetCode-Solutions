int mod=1e9+7;
int dx[]={-2,-1,1,2};
int dy[]={-2,-1,1,2};

class Solution {
    int rec(int i, int j, int n, vector<vector<vector<int>>> &dp){
        if(i<0||j<0||i>=4||j>=3) return 0;
        if(i==3 && (j==0||j==2)) return 0;
        if(n==0) return 1;
        if(dp[i][j][n]!=-1) return dp[i][j][n];
        int ans=0;
        for(int x=0; x<4; x++){
            for(int y=0; y<4; y++){
                if(abs(dx[x])==abs(dy[y])) continue;
                ans=(ans+rec(i+dx[x],j+dy[y],n-1,dp)%mod)%mod;
            }
        }
        return dp[i][j][n]=ans;
    }
public:
    int knightDialer(int n) {
        //[3][0] & [3][2] are invalid
        vector<vector<vector<int>>> dp(4,vector<vector<int>>(3,vector<int>(n+1,-1)));
        int ans=0;
        for(int i=0; i<4; i++){
            for(int j=0; j<3; j++){
                ans=(ans+rec(i,j,n-1,dp)%mod)%mod;
            }
        }
        return ans;
    }
};