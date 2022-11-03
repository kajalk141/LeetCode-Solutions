class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> mp;
        for(string &s:words){
            mp[s]++;
        }
        int res=0, mid=0;
        for(auto &x:mp){
            string s=x.first;
            string temp={s[1],s[0]};
            if(temp!=s && mp.find(temp)!=mp.end()) res+=min(mp[temp],mp[s])*2;
            if(temp==s){
                if(mp[s]%2==0) res+= mp[s]*2;
                else {
                    res+= (mp[s]-1)*2;
                    mid=2;
                }
            }
         }
        return res+mid;
    }
};