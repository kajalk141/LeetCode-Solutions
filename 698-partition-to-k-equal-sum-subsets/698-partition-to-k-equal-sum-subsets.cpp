int n;
class Solution {
    bool rec(int idx, int k, int curr, int sum, vector<int> &nums, vector<bool> &vis){
        if(k==1) return 1;
        if(curr>sum) return 0;
        if(curr==sum) return rec(0,k-1,0,sum,nums,vis);
        for(int i=idx; i<n; i++){
            if(nums[i]+curr>sum) break;
            if(vis[i]) continue;
            vis[i]=1;
            if(rec(idx+1,k,curr+nums[i],sum,nums,vis)) return 1;
            vis[i]=0;
            if(curr==0) break;
        }
        return 0;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        n=nums.size();
        for(int i=0; i<n; i++){
            sum+=nums[i];
        }
        if(sum%k!=0) return 0;
        sum/=k;
        vector<bool> vis(n,0);
        sort(nums.begin(), nums.end());
        return rec(0,k,0,sum,nums,vis);
    }
};