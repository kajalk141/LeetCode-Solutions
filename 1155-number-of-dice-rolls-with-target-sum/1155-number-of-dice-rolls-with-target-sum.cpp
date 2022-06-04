int mod=1e9+7;
class Solution {
    int rec(int i, int k, int req, vector<vector<int>> &dp){
        if(i==0 && req==0) return 1;
        if(req<0||i<0) return 0;
        if(dp[i][req]!=-1) return dp[i][req];
        int ans=0;
        for(int j=1; j<=k; j++){
            ans=(ans+rec(i-1,k,req-j,dp)%mod)%mod;
        }
        return dp[i][req]=ans;
        
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return rec(n,k,target,dp);
    }
};