class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int> bit(32,-1);
        for(int i=n-1; i>=0; i--){
            int farthest=-1;
            for(int b=0; b<32; b++){
                if(nums[i]&(1<<b))
                    bit[b]=i;
                else{
                    farthest=max(farthest,bit[b]);
                }
            }
            nums[i]=(farthest==-1?1:farthest-i+1);
        }
        return nums;
    }
};