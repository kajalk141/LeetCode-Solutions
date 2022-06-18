class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int mid=nums[n/2], res=0;
        for(auto num:nums) res+=abs(num-mid);
        return res;
    }
};