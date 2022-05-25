//rec(amount) return the minimum number of coins needed

class Solution {
    int rec(int amount, vector<int> &coins, vector<int> &dp){
        if(amount==0) return 0;
        if(dp[amount]!=-1) return dp[amount];
        int ans=1000000000;
        for(auto coin:coins){
            if(amount-coin>=0)
                ans=min(ans,1+rec(amount-coin,coins,dp));
        }
        return dp[amount]=ans;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        int ans=rec(amount,coins,dp);
        return ans==1000000000?-1:ans;
    }
};