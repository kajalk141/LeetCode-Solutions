int m,n;
int dy[]={-1,0,1};
class Solution {
    int rec(int i, int j1, int j2, vector<vector<int>>& grid, vector<vector<vector<int>>> &dp){
        if(i==m||j1==n||j2==n||j1<0||j2<0) return 0;
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int ans=0;
        for(auto p:dy){
            for(auto q:dy){
                int temp=rec(i+1,j1+p,j2+q,grid,dp);
                if(j1==j2) temp+=grid[i][j1];
                else temp+=grid[i][j1]+grid[i][j2];
                ans=max(ans,temp);
            }
        }
        return dp[i][j1][j2]=ans;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n,vector<int>(n,-1)));
        return rec(0,0,n-1,grid,dp);
    }
};