class Solution {
public:
    // int rec(int i, int prev, vector<int> &nums, vector<vector<int>> &dp){
    //     if(i<0) return 0;
    //     if(dp[i][prev]!=-1) return dp[i][prev];
    //     int ans=0;
    //     ans=max(ans, rec(i-1,prev,nums,dp));
    //     if(nums[i]<prev) ans=max(ans, 1+rec(i-1,nums[i],nums,dp));
    //     return dp[i][prev]=ans;
    // }
    
    int maxEnvelopes(vector<vector<int>>& v) {
        sort(v.begin(), v.end(), [](auto &a, auto &b){
            if(a[0]==b[0])
                return a[1]>b[1];
            return a[0]<b[0];
        });
        int n=v.size();
        vector<int> lis;
        for(int i=0; i<n; i++){
            auto it = lower_bound(lis.begin(), lis.end(), v[i][1]);
            if(it==lis.end())
                lis.push_back(v[i][1]);
            else
                *it = v[i][1];
        }
        return lis.size();
    }
};