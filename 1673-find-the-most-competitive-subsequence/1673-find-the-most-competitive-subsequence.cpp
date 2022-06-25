class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> res;
        int n=nums.size();
        for(int i=0; i<n; i++){
            // if(st.size()==k) break;
            while(!res.empty() && nums[i]<res.back() && res.size()+(n-i-1)>=k){
                res.pop_back();
            }
            if(res.size()<k) res.push_back(nums[i]);
        }
        return res;
    }
};