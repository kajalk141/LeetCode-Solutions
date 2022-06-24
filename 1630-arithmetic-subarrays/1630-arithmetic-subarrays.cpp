class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n=nums.size();
        int m=l.size();
        vector<bool> res(m,1);
        for(int i=0; i<m; i++){
            vector<int> v;
            for(int j=l[i]; j<=r[i]; j++) v.push_back(nums[j]);
            sort(v.begin(), v.end());
            int diff=INT_MAX;
            for(int j=1; j<(int)v.size(); j++){
                if(diff==INT_MAX) diff=v[j]-v[j-1];
                if(v[j]-v[j-1]!=diff){
                    res[i]=0;
                    break;
                }
            }
        }
        return res;
    }
};