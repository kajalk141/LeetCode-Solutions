class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum=0, n=nums.size();
        for(int num:nums) sum+=num;
        return sum-nums[0]*n;
    }
};