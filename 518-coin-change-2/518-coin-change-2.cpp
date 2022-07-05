int n;
class Solution {
    int rec(int i, int x, vector<int> &coins, vector<vector<int>> &dp){
        if(x==0) return 1;
        if(x<0) return 0;
        if(i>=n) return 0;
        if(dp[i][x]!=-1) return dp[i][x];
        int ans=0;
        for(int j=i; j<n; j++){
            if(coins[j]<=x) ans+=rec(j,x-coins[j],coins,dp);
        }
        return dp[i][x]=ans;
    }
public:
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());
        n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return rec(0,amount,coins,dp);
    }
};