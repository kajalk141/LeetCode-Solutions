class Solution {
public:
    vector<vector<string>> res;
    vector<string> temp;
    int n;
    vector<vector<string>> partition(string s) {
        n=s.size();
        vector<vector<bool>> dp(n, vector<bool>(n,0));
        for(int i=1; i<=n; i++){
            for(int j=0; j<=n-i; j++){
                if(i==1) dp[j][j]=1;
                else if(i==2) dp[j][j+1]=(s[j]==s[j+1]?1:0);
                else{
                    if(s[j]==s[j+i-1] && dp[j+1][j+i-2]==1)
                        dp[j][j+i-1]=1;
                }
            }
        }
        rec(0,dp,s);
        return res;
        
    }
    
    void rec(int i, vector<vector<bool>> &dp, string &s){
        if(i==n){
            res.push_back(temp);
            return;
        }
        for(int j=i; j<n; j++){
            if(dp[i][j]==1){
                temp.push_back(s.substr(i,j-i+1));
                rec(j+1, dp, s);
                temp.pop_back();
            }
        }
    }
};