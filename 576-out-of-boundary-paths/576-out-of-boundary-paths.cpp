int r,c;
int mod=1e9+7;
#define long long int lli
class Solution {
    int rec(int i, int j, int rem, vector<vector<vector<int>>> &dp){
        if(i<0||j<0||i>=r||j>=c) return 1;
        if(rem<=0) return 0;
        if(dp[i][j][rem]!=-1) return dp[i][j][rem]%mod;
        int ans=0;
        ans=(ans+rec(i-1,j,rem-1,dp)%mod)%mod;
        ans=(ans+rec(i+1,j,rem-1,dp)%mod)%mod;
        ans=(ans+rec(i,j+1,rem-1,dp)%mod)%mod;
        ans=(ans+rec(i,j-1,rem-1,dp)%mod)%mod;  
        return dp[i][j][rem]=ans;
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        r=m; c=n;
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(maxMove+1,-1)));
        return rec(startRow, startColumn, maxMove, dp);
    }
};