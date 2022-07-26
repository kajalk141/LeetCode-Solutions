class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size(), l=1, r=1, k=1;
        while(r<n){
            while(r<n && nums[r]==nums[r-1]) r++;
            if(r<n){
                nums[l++]=nums[r++];
                k++;
            }
        }
        return k;
    }
};