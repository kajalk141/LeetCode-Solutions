int mod=1e9+7;
class Solution {
public:
    int countPairs(vector<int>& nums) {
        map<int,int> mp;
        for(int num:nums) mp[num]++;
        // return mp[-572424];
        long long cnt=0;
        for(auto x:mp){
            if(x.second<=0) continue;
            // int k=1;
            for(int i=0; i<=21; i++){
                int k=pow(2,i);
                if(mp.find(k-x.first)==mp.end()) continue;
                if(2*x.first!=k) cnt+= (x.second*1ll*mp[k-x.first])%mod;
                else cnt+= ((x.second*1ll*(x.second-1))/2)%mod;
            }
            mp[x.first]=0;
            // mp[k-x.first]=0;
        }
        return cnt%mod;
    }
};

    