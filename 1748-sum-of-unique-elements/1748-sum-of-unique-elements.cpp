class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto i:nums) mp[i]++;
        int res=0;
        for(auto x:mp) if(x.second==1) res+=x.first;
        return res;
    }
};