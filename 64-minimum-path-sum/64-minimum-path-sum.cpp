int n, m;
class Solution {
    int rec(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(i==0 && j==0) return grid[i][j];
        if(i<0) return 100000000;
        if(j<0) return 100000000;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=grid[i][j]+min(rec(i-1,j,grid,dp),rec(i,j-1,grid,dp));
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return rec(n-1,m-1,grid,dp);
    }
};