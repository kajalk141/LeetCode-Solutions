class Solution {
public:
    int balancedStringSplit(string s) {
        int l=0,r=0,cnt=0;
        int n=s.size();
        for(int i=0; i<n; i++){
            if(s[i]=='L') l++;
            if(s[i]=='R') r++;
            if(r==l){
                cnt++;
                r=0; l=0;
            }
        }
        return cnt;
    }
};