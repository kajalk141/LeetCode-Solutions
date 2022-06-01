int n;
class Solution {
    int rec(int i, vector<int> &nums, vector<int> &dp){
        if(i>=n-1) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans=1e9;
        for(int jump=1; jump<=nums[i]; jump++){
            ans=min(ans,1+rec(i+jump,nums,dp));
        }
        return dp[i]=ans;
    }
public:
    int jump(vector<int>& nums) {
        n=nums.size();
        vector<int> dp(n,-1);
        return rec(0,nums,dp);
    }
};