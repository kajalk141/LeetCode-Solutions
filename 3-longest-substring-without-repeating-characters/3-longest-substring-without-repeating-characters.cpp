class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        map<char,int> mp;
        int temp=0, ans=0, start=-1;
        for(int i=0; i<n; i++){
            if(mp.find(s[i])==mp.end()) temp++;
            else{
                start=max(start,mp[s[i]]+1);
                temp=(i-start+1);
            }
            mp[s[i]]=i;
            ans=max(temp,ans);
        }
        return ans;
    }
};