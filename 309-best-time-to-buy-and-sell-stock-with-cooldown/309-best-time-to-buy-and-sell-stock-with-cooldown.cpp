int n;
class Solution {
    int rec(int i, bool stock, bool cooldown, vector<int> &prices, vector<vector<vector<int>>> &dp){
        if(i==n) return 0;
        if(dp[i][stock][cooldown]!=-1) return dp[i][stock][cooldown];
        int ans=0;
        if(!stock && !cooldown) ans=max(-prices[i]+rec(i+1,true,false,prices,dp), rec(i+1,false,false,prices,dp));
        if(!stock && cooldown) ans=rec(i+1,false,false,prices,dp);
        if(stock) ans=max(prices[i]+rec(i+1,false,true,prices,dp), rec(i+1,true,false,prices,dp));
        return dp[i][stock][cooldown]=ans;
    }
public:
    int maxProfit(vector<int>& prices) {
        n=prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2,-1)));
        return rec(0,0,0,prices,dp);
    }
};