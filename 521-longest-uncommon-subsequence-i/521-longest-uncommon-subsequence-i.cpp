class Solution {
public:
    int findLUSlength(string a, string b) {
        int n=a.size(), m=b.size();
        if(n!=m) return max(n,m);
        for(int i=0; i<n; i++) if(a[i]!=b[i]) return n;
        return -1;
    }
};