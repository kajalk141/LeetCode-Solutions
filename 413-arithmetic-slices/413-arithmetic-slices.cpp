class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size(), curr=0, res=0;
        if(n<3) return 0;
        int diff=nums[1]-nums[0];
        for(int i=2; i<n; i++){
            if(nums[i]-nums[i-1]==diff) curr++;
            else{
                curr=0;
                diff=nums[i]-nums[i-1];
            }
            res+=curr;
        }
        return res;
    }
};