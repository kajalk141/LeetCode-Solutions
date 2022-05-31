class Solution {
    int rec(int n, vector<int> &dp){
        if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];
        int i=1, ans=1e9;
        while(i*i<=n){
            ans=min(ans,1+rec(n-i*i,dp));
            i++;
        }
        return dp[n]=ans;
    }
public:
    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        return rec(n,dp);
    }
};