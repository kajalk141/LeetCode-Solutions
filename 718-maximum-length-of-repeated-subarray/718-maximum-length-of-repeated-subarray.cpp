class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(), m=nums2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        int res=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(nums1[i]==nums2[j]){
                    dp[i][j]=1;
                    if(i-1>=0 && j-1>=0)
                        dp[i][j]+=dp[i-1][j-1];
                    res=max(res,dp[i][j]);
                }
            }
        }
        return res;
    }
};