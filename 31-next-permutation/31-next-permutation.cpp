class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        for(int i=n-1; i>=0; i--){
            if(i==0) reverse(nums.begin(),nums.end());
            else if(nums[i]>nums[i-1]){
                for(int j=i; j<n; j++){
                    if(nums[j]>nums[i-1] && (j+1==n || nums[j+1]<=nums[i-1])){
                        int temp=nums[i-1];
                        nums[i-1]=nums[j];
                        nums[j]=temp;
                        reverse(nums.begin()+i, nums.end());
                        break;
                    }
                }
                break;
            }
        }
        return;
    }
};