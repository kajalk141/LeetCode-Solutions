int n,m;
class Solution {
    int rec(int i, int j, vector<vector<int>>& dungeon, vector<vector<int>>& dp){
        if(i==n-1 && j==m-1){
            if(dungeon[i][j]>0) return dp[i][j]=1;
            else return dp[i][j]=1+abs(dungeon[i][j]);
        }
        if(i>=n || j>=m) return 1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int right=rec(i,j+1,dungeon,dp);
        int down=rec(i+1,j,dungeon,dp);
        int ans=min(right,down);
        if(dungeon[i][j]>0){
            if(dungeon[i][j]>=ans){
                ans=1;
            }
            else{
                ans=ans-dungeon[i][j];
            }
        }
        else{
            ans+=abs(dungeon[i][j]);
        }
        return dp[i][j]= ans;
    }
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        n=dungeon.size();
        m=dungeon[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return rec(0,0,dungeon,dp);
    }
};