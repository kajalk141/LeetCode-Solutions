int mod=1e9+7;
class Solution {
    // 0 means empty
    int rec(int i, int mask, vector<vector<int>> &dp){
        if(i==0){
            if(mask==0) return 1;
            return 0;
        }
        if(dp[i][mask]!=-1) return dp[i][mask];
        int ans=0;
        if((mask&(1<<0))==0 && (mask&(1<<1))==0){
            ans=(ans+rec(i-1,3,dp))%mod; //2 dominoes horizontal
            ans=(ans+rec(i-1,0,dp))%mod; //1 domino vertical
            ans=(ans+rec(i-1,1,dp))%mod;
            ans=(ans+rec(i-1,2,dp))%mod;
        }
        else if((mask&(1<<0))==0){
            ans=(ans+rec(i-1,1,dp))%mod;
            ans=(ans+rec(i-1,3,dp))%mod;
        }
        else if((mask&(1<<1))==0){
            ans=(ans+rec(i-1,2,dp))%mod;
            ans=(ans+rec(i-1,3,dp))%mod;
        }
        else{
            ans=(ans+rec(i-1,0,dp))%mod;
        }
        return dp[i][mask]=ans;
    }
public:
    int numTilings(int n) {
        vector<vector<int>> dp(n+1, vector<int>(4,-1));
        return rec(n,0,dp);
    }
};