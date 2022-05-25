int n,m;
class Solution {
    int rec(int i, int j, vector<vector<char>> &matrix, vector<vector<int>> &dp){
        if(i>=n || j>=m) return 0;
        if(matrix[i][j]=='0') return dp[i][j]=0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=1000000000;
        ans=min(ans,rec(i+1,j,matrix,dp));
        ans=min(ans,rec(i,j+1,matrix,dp));
        ans=min(ans,rec(i+1,j+1,matrix,dp));
        return dp[i][j]=1+ans;
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        n=matrix.size(); 
        m=matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]=='0') continue;
                ans=max(ans,rec(i,j,matrix,dp));
            }
        }
        return ans*ans;
    }
};