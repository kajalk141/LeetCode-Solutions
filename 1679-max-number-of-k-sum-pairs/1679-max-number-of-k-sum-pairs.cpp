class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int,int> mp;
        for(int num:nums) mp[num]++;
        int cnt=0;
        for(auto x:mp){
            if(x.second<=0) continue;
            if(2*x.first!=k) cnt+= min(x.second, mp[k-x.first]);
            else cnt+= x.second/2;
            x.second=0;
            mp[k-x.first]=0;
        }
        return cnt;
    }
};