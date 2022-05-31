int len;
class Solution {
    int rec(int i, vector<string> &strs, int m, int n, vector<vector<vector<int>>> &dp){
        if(m<0 || n<0) return -1e9;
        if(i==len) return 0;
        if(dp[i][m][n]!=-1) return dp[i][m][n];
        int c1=0, c2=0;
        for(auto c:strs[i]){
            if(c=='0') c1++;
            else c2++;
        }
        return dp[i][m][n]=max(1+rec(i+1,strs,m-c1,n-c2,dp), rec(i+1,strs,m,n,dp));
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        len=strs.size();
        vector<vector<vector<int>>> dp(len, vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return rec(0,strs,m,n,dp);
    }
};