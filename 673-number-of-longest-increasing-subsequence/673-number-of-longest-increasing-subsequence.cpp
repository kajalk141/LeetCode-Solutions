class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,1);
        vector<int> len(n+1,1);
        int ans=0;
        for(int i=0; i<n; i++){
            int temp;
            for(int j=i-1; j>=0; j--){
                if(nums[i]>nums[j]){
                    if(dp[j]+1>dp[i]){
                        dp[i]=dp[j]+1;
                        len[i]=len[j];
                    }
                    else if(dp[i]==dp[j]+1) len[i]+=len[j];
                }
            }
            ans=max(ans,dp[i]);
        }
        // return ans;
        int res=0;
        for(int i=0; i<n; i++) if(dp[i]==ans) res+=len[i];
        return res;
    }
};