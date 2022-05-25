class Solution {
    bool rec(int i, int sum, vector<int> &nums, vector<vector<int>> &dp){
        if(sum<0) return false;
        if(sum==0) return true;
        if(i<0) return false;
        if(dp[i][sum]!=-1) return dp[i][sum];
        return dp[i][sum]=rec(i-1,sum,nums,dp)||rec(i-1,sum-nums[i],nums,dp);
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0; i<n; i++){
            sum+=nums[i];
        }
        if(sum%2==1) return false;
        sum/=2;
        vector<vector<int>> dp(n, vector<int>(sum+1,-1));
        return rec(n-1,sum,nums,dp);
    }
};