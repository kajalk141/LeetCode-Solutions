class Solution {
    int rec(int i, vector<int> &nums, vector<int> &dp){
        if(i==0) return 1;
        if(dp[i]!=-1) return dp[i];
        int ans=1;
        for(int j=i-1; j>=0; j--){
            if(nums[i]>nums[j]){
                ans=max(ans,1+rec(j,nums,dp));
            }
        }
        return dp[i]=ans;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        int ans=0;
        for(int i=0; i<n; i++){
            ans=max(ans,rec(i,nums,dp));
        }
        return ans;
    }
};