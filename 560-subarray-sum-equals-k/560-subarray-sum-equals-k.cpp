typedef long long ll;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        ll n=nums.size(), sum=0, res=0;
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            sum+=nums[i];
            if(sum==k) res++;
            if(mp[sum-k]) res+=mp[sum-k];
            mp[sum]++;
        }
        return res;
    }
};