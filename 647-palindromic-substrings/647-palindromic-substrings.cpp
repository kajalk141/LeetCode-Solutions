class Solution {
    bool rec(int i, int j, string &s, vector<vector<int>> &dp){
        if(i>=j) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        bool ans=1;
        if(s[i]==s[j]){
            ans=ans && rec(i+1,j-1,s,dp);
        }
        else ans=0;
        return dp[i][j]=ans;
    }
public:
    int countSubstrings(string s) {
        int n=s.size(), cnt=0;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(s[i]==s[j] && rec(i,j,s,dp)) cnt++;
            }
        }
        return cnt;
    }
};