class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<int> res;
        for(int i=0; i<(int)nums.size(); i++){
            if(nums[abs(nums[i])-1]<0) res.push_back(abs(nums[i]));
            nums[abs(nums[i])-1]*=-1;
        }
        return res;
    }
};