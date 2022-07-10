class Solution {
    int rec(int i, int j, string &s, string &t, vector<vector<int>> &dp){
        if(i<0||j<0) return abs(i-j);
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MAX;
        if(s[i]==t[j]) ans=rec(i-1, j-1, s, t, dp);
        else{
            ans=min(ans, 1+rec(i, j-1, s, t, dp)); //insert
            ans=min(ans, 1+rec(i-1, j, s, t, dp)); //delete
            ans=min(ans, 1+rec(i-1, j-1, s, t, dp)); //replace
        }
        return dp[i][j]=ans;
    }
public:
    int minDistance(string s, string t) {
        int n=s.size(), m=t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        return rec(n-1, m-1, s, t, dp);
    }
};