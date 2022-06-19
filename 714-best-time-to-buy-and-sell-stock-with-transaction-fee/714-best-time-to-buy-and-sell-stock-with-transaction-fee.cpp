int n;
class Solution {
    int rec(int i, bool stock, vector<int> &prices, int fee, vector<vector<int>> &dp){
        if(i==n) return 0;
        if(dp[i][stock]!=-1) return dp[i][stock];
        int ans=0;
        if(stock) ans=max(prices[i]+rec(i+1,false,prices,fee,dp)-fee, rec(i+1,true,prices,fee,dp));
        if(!stock) ans=max(rec(i+1,true,prices,fee,dp)-prices[i], rec(i+1,false,prices,fee,dp));
        return dp[i][stock]=ans;
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return rec(0,0,prices,fee,dp);
    }
};