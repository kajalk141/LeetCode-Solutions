int n;
class Solution {
    int rec(int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &dp){
        if(i==n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=triangle[i][j]+min(rec(i+1,j,triangle,dp),rec(i+1,j+1,triangle,dp));
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        // for(int i=1; i<=n; i++){
        //     vector<int> temp(i,-1);
        //     dp.push_back(temp);
        // }
        return rec(0,0,triangle,dp);
    }
};