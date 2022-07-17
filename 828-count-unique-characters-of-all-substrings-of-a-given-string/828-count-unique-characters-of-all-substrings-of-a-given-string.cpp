class Solution {
public:
    int uniqueLetterString(string s) {
        int n=s.size();
        unordered_map<char,vector<int>> mp;
        for(int i=0; i<n; i++) mp[s[i]].push_back(i);
        int cnt=0;
        for(auto x: mp){
            vector<int> v=x.second;
            int len=v.size(), l=0, r=0;
            for(int i=0; i<len; i++){
                l= i==0 ? v[i]+1 : v[i]-v[i-1];
                r= i==len-1 ? n-v[i] : v[i+1]-v[i];
                cnt+= (l*r);
            }
        }
        return cnt;
    }
};