class Solution {
public:
    bool isNStraightHand(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int> mp;
        for(int num:nums) mp[num]++;
        int parts=0;
        for(auto x:mp){
            // if(x.second==0) continue;
            int start=x.first;
            // int freq=x.second;
            bool flag=1;
            while(x.second>0){
                for(int i=1; i<k; i++){
                    if(!mp[start+i]){
                        flag=0;
                        break;
                    }
                }
                if(flag==0) x.second=0;
                else{
                    x.second--;
                    for(int i=1; i<k; i++) mp[start+i]--;
                    parts++;
                }
            }
        }
        return parts*k==n?1:0;
        
    }
};