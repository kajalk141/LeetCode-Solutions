class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        sort(nums.begin(), nums.end());
        int n=numsDivide.size(), gcd=numsDivide[0];
        for(int i=0; i<=n-1; i++){
            gcd=__gcd(gcd,numsDivide[i]);
        }
        for(int i=0; i<(int)nums.size(); i++){
            if(gcd%nums[i]==0) return i;
        }
        return -1;
    }
};