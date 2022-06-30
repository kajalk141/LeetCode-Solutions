class Solution {
    int rec(int i, int j, string &s, string &t, vector<vector<int>> &dp){
        if(i<0||j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans;
        if(s[i]==t[j]) ans=1+rec(i-1,j-1,s,t,dp);
        else ans=max(rec(i-1,j,s,t,dp), rec(i,j-1,s,t,dp));
        return dp[i][j]=ans;
    }
public:
    int minInsertions(string s) {
        string t=s;
        reverse(s.begin(), s.end());
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return n-rec(n-1,n-1,s,t,dp);
    }
};