int total,n;
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        n=nums.size();
        total=0;
        for(auto num:nums) total+=num;
        int res=0, temp=total/2;
        for(int i=0; i<=temp; i++){
            if(abs(i-(total-i))==abs(target)){
                vector<vector<int>> dp(n,vector<int>(temp+1,-1));
                res+=rec(n-1,nums,i,dp);
            } 
                
        }
        return res;
    }
    
    int rec(int i, vector<int> &nums, int sum, vector<vector<int>> &dp){
        if(sum<0) return 0;
        if(sum==0 && i==-1) return 1;
        if(i<0) return 0;
        if(dp[i][sum]!=-1) return dp[i][sum];
        return dp[i][sum]=rec(i-1,nums,sum-nums[i],dp)+rec(i-1,nums,sum,dp);
    }
};