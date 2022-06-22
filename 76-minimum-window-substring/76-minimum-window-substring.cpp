class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size(), m=t.size();
        if(m>n) return "";
        vector<int> freq(130,0);
        for(char c:t) freq[c]++;
        int l=0, r=0, cnt=m, res=INT_MAX, start=-1;
        while(r<n){
            if(freq[s[r]]-- >0) cnt--;
            while(cnt==0){
                if(r-l+1<res){
                    res=r-l+1;
                    start=l;
                }
                if(freq[s[l++]]++ ==0) cnt++;
            }
            r++;
        }
        return res==INT_MAX?"":s.substr(start,res);
    }
};