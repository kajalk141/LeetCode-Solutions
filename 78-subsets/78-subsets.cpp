class Solution {
public:
    vector<vector<int>> res;
    int n;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        res.push_back(temp);
        n=nums.size();
        rec(0,temp,nums);
        return res;
    }
    
    void rec(int i, vector<int> &temp, vector<int> &nums){
        if(i==n) return;
        for(int j=i; j<n; j++){
            temp.push_back(nums[j]);
            res.push_back(temp);
            rec(j+1,temp,nums);
            temp.pop_back();
        }
        return;
    }
};