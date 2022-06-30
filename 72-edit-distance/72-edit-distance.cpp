class Solution {
    int rec(int i, int j, string &s, string &t, vector<vector<int>> &dp){
        if(i<0 || j<0) return abs(i-j);
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MAX;
        if(s[i]==t[j]) ans=rec(i-1,j-1,s,t,dp);
        else{
            ans=min(ans, 1+rec(i-1,j,s,t,dp)); //deleting
            ans=min(ans, 1+rec(i,j-1,s,t,dp)); //inserting
            ans=min(ans, 1+rec(i-1,j-1,s,t,dp)); //replacing
        }
        return dp[i][j]=ans;
    }
public:
    int minDistance(string word1, string word2) {
        int n=word1.size(), m=word2.size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return rec(n-1,m-1,word1,word2,dp);
    }
};