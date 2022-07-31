class Solution {
public:
    vector<vector<int>> res;
    int n;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        n=nums.size();
        rec(0,n-1,nums);
        return res;
    }
    
    void rec(int l, int r, vector<int> &nums){
        if(l==r){
            res.push_back(nums);
            return;
        }
        unordered_set<int> s;
        for(int i=l; i<=r; i++){
            if(s.find(nums[i])!=s.end()) continue;
            s.insert(nums[i]);
            swap(nums[l],nums[i]);
            rec(l+1,r,nums);
            swap(nums[l],nums[i]);
        }
        return;
    }    
};