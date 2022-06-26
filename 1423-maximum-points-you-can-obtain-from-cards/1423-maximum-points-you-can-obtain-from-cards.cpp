class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=1; i<n; i++) nums[i]+=nums[i-1];
        if(n==k) return nums[n-1];
        int res=nums[n-k-1];
        for(int i=n-k; i<n; i++) res=min(res,nums[i]-nums[i-n+k]);
        return nums[n-1]-res;
    }
};