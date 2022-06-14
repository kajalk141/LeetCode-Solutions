class Solution {
    int rec(int i, int j, string &s, string &t, vector<vector<int>> &dp){
        if(i<0||j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        if(s[i]==t[j]) return dp[i][j]=1+rec(i-1,j-1,s,t,dp);
        else{
            return dp[i][j]=max(rec(i-1,j,s,t,dp), rec(i,j-1,s,t,dp));
        }
    }
public:
    int longestCommonSubsequence(string s, string t) {
        int n=s.size(), m=t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return rec(n-1,m-1,s,t,dp);
    }
};