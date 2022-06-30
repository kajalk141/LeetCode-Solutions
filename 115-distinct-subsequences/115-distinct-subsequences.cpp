class Solution {
    int rec(int i, int j, string &s, string &t,vector<vector<int>> &dp){
        if(j<0) return 1;
        if(i<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        if(s[i]==t[j]) ans=rec(i-1,j-1,s,t,dp);
        ans+= rec(i-1,j,s,t,dp);
        return dp[i][j]=ans;
    }
public:
    int numDistinct(string s, string t) {
        int n=s.size(), m=t.size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return rec(n-1,m-1,s,t,dp);
    }
};