typedef pair<int,int> pii;
int n,m;
class Solution {
public:
    bool check(int i, int j, queue<pii> &q, vector<vector<int>>& dp){
        if(i<0||i>=n||j<0||j>=m) return 0;
        if(dp[i][j]!=1e5) return 0;
        q.push({i,j});
        return 1;
    }
    
    int maxDistance(vector<vector<int>>& grid) {
        n=grid.size(); m=grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m,1e5));
        queue<pii> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    dp[i][j]=0;
                }
            }
        }
        if((int)q.size()==0||(int)q.size()==m*n) return -1;
        int res=0;
        while(!q.empty()){
            int r=q.front().first, c=q.front().second;
            q.pop();
            res=max(res, dp[r][c]);
            // if(grid[r][c]==0) continue;
            if(check(r+1,c,q,dp)) dp[r+1][c]=min(dp[r+1][c], dp[r][c]+1);
            if(check(r-1,c,q,dp)) dp[r-1][c]=min(dp[r-1][c], dp[r][c]+1);
            if(check(r,c+1,q,dp)) dp[r][c+1]=min(dp[r][c+1], dp[r][c]+1);
            if(check(r,c-1,q,dp)) dp[r][c-1]=min(dp[r][c-1], dp[r][c]+1);
        }
        return res;
    }
};