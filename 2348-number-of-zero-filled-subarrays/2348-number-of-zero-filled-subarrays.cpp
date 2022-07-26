typedef long long ll;
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n=nums.size();
        ll len=0, res=0;
        for(int i=0; i<n; i++){
            if(nums[i]==0) len++;
            else len=0;
            res+=len;
        }
        return res;
    }
};