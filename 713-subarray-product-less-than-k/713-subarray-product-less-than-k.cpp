typedef long long ll;
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        ll n=nums.size(), l=0, r=0, pro=1, res=0;
        while(r<n){
            pro*=nums[r];
            while(pro>=k) pro/=nums[l++];
            res+=(r-l+1);
            r++;
        }
        return res;
    }
};