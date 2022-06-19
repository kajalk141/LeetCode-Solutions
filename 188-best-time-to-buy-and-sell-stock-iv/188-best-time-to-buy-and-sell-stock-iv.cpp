int n;
class Solution {
    int rec(int i, int k, bool stock, vector<int>& prices, vector<vector<vector<int>>> &dp){
        if(k==0 || i==n) return 0;
        if(dp[i][k][stock]!=-1) return dp[i][k][stock];
        int ans=0;
        if(stock) ans=max(prices[i]+rec(i+1,k-1,false,prices,dp), rec(i+1,k,true,prices,dp));
        if(!stock) ans=max(-prices[i]+rec(i+1,k,true,prices,dp), rec(i+1,k,false,prices,dp));
        return dp[i][k][stock]=ans;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(k+1,vector<int>(2,-1)));
        return rec(0,k,0,prices,dp);
    }
};