class Solution {
    bool rec(int i, int j, string &s, string &t, vector<vector<int>> &dp){
        if(j<0 && i<0) return true;
        if(j<0) return false;
        if(i<0){
            while(j>=0) if(t[j--]!='*') return false; //an empty sequence can only be matched to a '*...'
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        bool  ans;
        if(s[i]==t[j] || t[j]=='?') ans=rec(i-1,j-1,s,t,dp);
        else if(t[j]=='*') ans=rec(i,j-1,s,t,dp)||rec(i-1,j,s,t,dp); //t[j]='*' is matched with an empty sequence or s[i] is the starting point of a sequence being matched to '*'//
        else ans=false;
        return dp[i][j]=ans;
    }
public:
    bool isMatch(string s, string p) {
        int n=s.size(), m=p.size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return rec(n-1,m-1,s,p,dp);
    }
};