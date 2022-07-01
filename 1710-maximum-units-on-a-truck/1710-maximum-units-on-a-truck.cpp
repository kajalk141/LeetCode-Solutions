class Solution {
public:
    int maximumUnits(vector<vector<int>>& box, int truck) {
        int curr=0, ans=0;
        sort(box.begin(),box.end(), [](auto &a, auto &b){
            if(a[1]==b[1]) return a[0]<b[0];
            return a[1]>b[1];
        });
        for(auto x:box){
            ans+=min(truck-curr,x[0])*x[1];
            curr+=min(truck-curr,x[0]);
            if(curr>=truck) break;
        }
        return ans;
    }
};