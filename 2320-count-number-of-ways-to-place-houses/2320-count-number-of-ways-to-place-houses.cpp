int mod=1e9+7;
class Solution {
public:
    int countHousePlacements(int n) {
        vector<int> dp(n+1,-1);
        long long res=rec(n,dp);
        return (int)((res*res)%mod);
    }
    
    int rec(int i, vector<int> &dp){
        if(i<=0) return 1;
        // if(i==1) return 2;
        if(dp[i]!=-1) return dp[i];
        return dp[i]=(rec(i-1,dp)+rec(i-2,dp))%mod;
    }
};