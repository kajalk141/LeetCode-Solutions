typedef pair<int,int> pii;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        vector<vector<int>> res;
        for(int i=0; i<n; i++){
            long long reqq=target-nums[i];
            for(int j=i+1; j<n; j++){
                long long req=reqq-nums[j]; int l=j+1, r=n-1;
                while(l<r){
                    long long sum=nums[l]+nums[r];
                    if(sum==req){
                        res.push_back({nums[i],nums[j],nums[l],nums[r]});
                        while(l<r && nums[l]==nums[l+1]) l++; 
                        l++; r--;
                    }
                    else if(sum>req) r--;
                    else l++;
                }
                while(j+1<n && nums[j]==nums[j+1]) j++;
            }
            while(i+1<n && nums[i]==nums[i+1]) i++;
        }
        return res;
    }
};