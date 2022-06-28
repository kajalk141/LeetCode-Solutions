int m,n;
class Solution {
    int rec(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i==n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int res=INT_MAX;
        for(int k=0; k<n; k++){
            if(k==j) continue;
            res=min(res, grid[i][j]+rec(i+1,k,grid,dp));
        }
        if(res==INT_MAX) res=grid[i][j];
        return dp[i][j]=res;
    }
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
        int ans=INT_MAX;
        for(int j=0; j<n; j++) ans=min(ans,rec(0,j,grid,dp));
        return ans;
    }
};