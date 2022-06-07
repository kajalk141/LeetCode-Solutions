int mod=1e9+7;
class Solution {
    int rec(int i, int steps, int n, vector<vector<int>> &dp){
        if(steps==0 && i==0) return 1;
        if(i<0||i>=n||steps<=0||i>steps) return 0;
        if(dp[i][steps]!=-1) return dp[i][steps];
        int ans=rec(i,steps-1,n,dp);
        ans=(ans+rec(i-1,steps-1,n,dp))%mod;
        ans=(ans+rec(i+1,steps-1,n,dp))%mod;
        return dp[i][steps]=ans;
    }
public:
    int numWays(int steps, int n) {
        vector<vector<int>> dp(600,vector<int>(steps+1,-1));
        return rec(0,steps,n,dp);
    }
};