class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int a=nums[n-1];
        int b=nums[n-2]*nums[n-3], c=nums[0]*nums[1];
        return a>0?a*max(b,c):a*min(b,c);
    }
};