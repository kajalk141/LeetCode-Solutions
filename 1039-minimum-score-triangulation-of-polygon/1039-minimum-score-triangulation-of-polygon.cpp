class Solution {
    int rec(int i, int j, vector<int> &values, vector<vector<int>> &dp){
        if((i==j)||(i+1==j)) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=1e8;
        for(int k=i+1; k<j; k++){
            int temp=(values[i]*values[j]*values[k]);
            temp=temp+rec(i,k,values,dp);
            temp+=rec(k,j,values,dp);
            ans=min(ans,temp);
        }
        return dp[i][j]=ans;
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return rec(0,n-1,values,dp);
    }
};