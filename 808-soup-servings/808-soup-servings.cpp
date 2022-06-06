class Solution {
    double rec(int a, int b, vector<vector<double>> &dp){
        if(a==0 && b==0) return 0.5;
        if(a==0 && b>0) return 1;
        if(a>0 && b==0) return 0;
        if(dp[a][b]!=-1) return dp[a][b];
        double ans=0;
        ans=ans+0.25*rec(max(0,a-100),b,dp);
        ans=ans+0.25*rec(max(0,a-75), max(0,b-25),dp);
        ans=ans+0.25*rec(max(0,a-50), max(0,b-50),dp);
        ans=ans+0.25*rec(max(0,a-25), max(0,b-75),dp);
        return dp[a][b]=ans;
    }
public:
    double soupServings(int n) {
        if(n>=5000) return 1;
        vector<vector<double>> dp(n+1,vector<double>(n+1,-1));
        return rec(n,n,dp);
    }
};