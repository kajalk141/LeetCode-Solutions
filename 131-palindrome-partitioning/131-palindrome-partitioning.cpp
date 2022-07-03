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
public:
    vector<vector<string>> res;
    vector<string> temp;
    
    void rec(int i, string &s, vector<vector<int>> &dp){
        if(i==n){
            res.push_back(temp);
            return;
        }
        for(int j=i; j<n; j++){
            if(dp[i][j]==1){
                temp.push_back(s.substr(i,j-i+1));
                rec(j+1,s,dp);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(s[i]==s[j] && rec(i+1,j-1,s,dp)){
                    dp[i][j]=1;
                }
                else dp[i][j]=0;
            }
        }
        rec(0,s,dp);
        return res;
    }
};