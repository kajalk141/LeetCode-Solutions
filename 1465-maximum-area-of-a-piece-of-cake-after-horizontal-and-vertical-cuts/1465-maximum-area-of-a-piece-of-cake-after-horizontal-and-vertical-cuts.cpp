int mod=1e9+7;
class Solution {
public:
    int maxArea(int h, int w, vector<int>& ho, vector<int>& ve) {
        sort(ho.begin(), ho.end());
        ho.push_back(h);
        sort(ve.begin(), ve.end());
        ve.push_back(w);
        long long last=0, mx=0, mxc=0;
        for(int n:ho){
            mx=max(mx,n-last);
            last=n;
        }
        mx%=mod;
        last=0;
        for(int n:ve){
            mxc=max(mxc,n-last);
            last=n;
        }
        mxc%=mod;
        return (int)((mx*mxc)%mod);
    }
};