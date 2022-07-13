class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size(), sum=0, res=INT_MIN;
        for(int i=0; i<n; i++){
            if(i>=k) sum-=nums[i-k];
            sum+=nums[i];
            if(i>=k-1) res=max(res,sum);
        }
        return (double)res/k;
    }
};