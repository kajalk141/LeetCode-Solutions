class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        pair<int,int> mx,mn;
        mx.first=INT_MIN;
        mn.first=INT_MAX;
        for(int i=0; i<n; i++){
            if(nums[i]>mx.first){
                mx.first=nums[i];
                mx.second=i;
            }
            if(nums[i]<mn.first){
                mn.first=nums[i];
                mn.second=i;
            }
        }
        int i=min(mn.second,mx.second), j=max(mn.second,mx.second);
        // if(i==j) return min(i+1,n-i);
        return min(i+1+n-j, min(j+1, n-i));
    }
};