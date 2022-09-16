class Solution {
public:
    int n,m;
    int rec(int l, int r, vector<int>& nums, vector<int>& multi, vector<vector<int>> &dp){
        int i=l+r;
        if(i>=m) return 0;
        if(dp[l][r]!=INT_MAX) return dp[l][r];
        int left=multi[i]*nums[l]+rec(l+1,r,nums,multi,dp);
        int right=multi[i]*nums[n-1-r]+rec(l,r+1,nums,multi,dp);
        return dp[l][r]=max(left,right);
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        n=nums.size(); m=multipliers.size();
        vector<vector<int>> dp(m+1, vector<int>(m+1,INT_MAX));
        return rec(0,0,nums,multipliers,dp);
    }
};