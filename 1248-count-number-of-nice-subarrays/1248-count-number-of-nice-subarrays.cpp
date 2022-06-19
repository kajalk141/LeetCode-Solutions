class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size(), res=0, help=0, l=0;
        for(int i=0; i<n; i++){
            if(nums[i]%2==0) nums[i]=0;
            else nums[i]=1;
            if(i) nums[i]+=nums[i-1];
        }
        map<int,int> mp;
        for(auto num:nums) mp[num]++;
        // return mp[0];
        int ele=k;
        while(mp.find(ele)!=mp.end()){
            // if(mp.find(ele-k)!=mp.end()) second=mp.fi
            res+= mp[ele]*(1+max(0,mp[ele-k]-(ele==k?0:1)));
            ele++;
        }
        return res;
        
    }
};