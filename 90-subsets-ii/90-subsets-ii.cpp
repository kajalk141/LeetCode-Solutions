class Solution {
public:
    vector<vector<int>> res;
    int n;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        res.push_back(temp);
        n=nums.size();
        sort(nums.begin(),nums.end());
        rec(0,nums,temp);
        return res;
    }
    
    void rec(int i, vector<int> &nums, vector<int> &temp){
        if(i==n) return;
        for(int j=i; j<n; j++){
            if(j!=i && nums[j]==nums[j-1]) continue;
            temp.push_back(nums[j]);
            res.push_back(temp);
            rec(j+1,nums,temp);
            temp.pop_back();
        }
        return;
    }
};