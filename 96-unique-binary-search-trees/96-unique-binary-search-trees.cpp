class Solution {
    int rec(int n, vector<int> &dp){
        if(n==0) return 1;
        if(dp[n]!=-1) return dp[n];
        int ans=0;
        for(int i=0; i<n; i++){
            ans=ans+(rec(i,dp)*rec(n-i-1,dp));
        }
        return dp[n]=ans;
    }
public:
    int numTrees(int n) {
        vector<int> dp(n+1,-1);
        return rec(n,dp);
    }
};