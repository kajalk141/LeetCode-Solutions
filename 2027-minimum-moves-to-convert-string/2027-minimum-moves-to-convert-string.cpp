class Solution {
public:
    int minimumMoves(string s) {
        int n=s.size(), cnt=0;
        for(int i=0; i<n; i++){
            if(s[i]=='O') continue;
            for(int j=i; j<min(n,i+3); j++){
                s[j]='O';
            }
            cnt++;
        }
        return cnt;
    }
};