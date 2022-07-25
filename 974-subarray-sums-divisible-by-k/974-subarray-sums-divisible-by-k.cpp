class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int> mp;
        mp[0]=1;
        int sum=0,r,cnt=0;
        for(int i=0; i<(int)nums.size(); i++){
            sum+=nums[i];
            r=sum%k;
            if(r<0) r+=k;
            cnt+=mp[r];
            mp[r]++;
        }
        return cnt;
    }
};