int n;
class Solution {
    bool rec(int i, int j, string &s, vector<vector<int>> &dp){
        if(i>=j) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        bool ans;
        if(s[i]==s[j]) ans=rec(i+1,j-1,s,dp);
        else ans=0;
        return dp[i][j]=ans;
    }
    
    bool rec2(int i, int cut, string &s, vector<vector<int>> &dp, vector<vector<int>> &dp2){
        if(i==n && cut==0) return true;
        if(cut<=0 || i>=n) return false;
        if(dp2[i][cut]!=-1) return dp2[i][cut];
        bool ans=false;
        for(int j=i; j<n; j++){
            if(dp[i][j]!=1) continue;
            ans=ans||rec2(j+1,cut-1,s,dp,dp2);
        }
        return dp2[i][cut]=ans;
    }
    
public:
    bool checkPartitioning(string s) {
        n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                dp[i][j]=rec(i,j,s,dp);
            }
        }
        // return dp[0][1];
        vector<vector<int>> dp2(n, vector<int>(4,-1));
        return rec2(0,3,s,dp,dp2);
    }
};