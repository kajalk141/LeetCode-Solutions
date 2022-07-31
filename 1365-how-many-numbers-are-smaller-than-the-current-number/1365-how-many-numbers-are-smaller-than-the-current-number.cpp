class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> freq(101,0);
        for(int num:nums) freq[num]++;
        for(int i=1; i<=100; i++) freq[i]+=freq[i-1];
        for(int i=0; i<(int)nums.size(); i++){
            if(nums[i]==0) continue;
            nums[i]=freq[nums[i]-1];
        }
        return nums;
    }
};