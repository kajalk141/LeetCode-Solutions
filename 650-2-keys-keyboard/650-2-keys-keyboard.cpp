class Solution {
    int rec(int i, int n, int l, vector<vector<int>> &dp){
        if(i==n) return 0;
        if(i>n) return 1e9;
        if(dp[i][l]!=-1) return dp[i][l];
        return dp[i][l]=min(2+rec(i+i,n,i,dp), 1+rec(i+l,n,l,dp));
    }
public:
    int minSteps(int n) {
        if(n==1) return 0;
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return 2+rec(2,n,1,dp);
    }
};