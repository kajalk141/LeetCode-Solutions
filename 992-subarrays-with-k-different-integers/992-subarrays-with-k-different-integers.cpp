class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
    
    int atmost(vector<int> &nums, int k){
        int n=nums.size(), res=0;
        vector<int> freq(20005,0);
        int i=0, j=0, cnt=0;
        while(j<n){
            if(freq[nums[j++]]++ ==0) cnt++;
            while(cnt>k){
                if(--freq[nums[i]]==0) cnt--;
                i++;
            }
            res+= j-i+1;
        }
        return res;
    }
};