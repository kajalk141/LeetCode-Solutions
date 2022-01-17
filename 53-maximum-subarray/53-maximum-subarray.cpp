class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr=0, res=INT_MIN;
        for(int i=0; i<nums.size(); i++){
            curr+=nums[i];
            res=max(res,curr);
            if(curr<0){
                curr=0;
            }
        }
        return res;
    }
};