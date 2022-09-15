class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n=changed.size();
        if(n%2) return {};
        map<int,int> mp;
        for(int i:changed)
            mp[i]++;
        vector<int> res;
        for(auto x:mp){
            if(x.second==0) continue;
            if(mp[x.first*2]<mp[x.first]) return {};
            int temp=x.second;
            if(x.first==0){
                temp/=2;
                while(temp--)
                    res.push_back(x.first);
                continue;
            }
            while(temp--){
                res.push_back(x.first);
                mp[x.first*2]--;
            } 
        }
        return res;
    }
};