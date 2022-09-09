class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), [](auto &a, auto &b){
            if(a[0]==b[0])
                return a[1]>b[1];
            return a[0]<b[0];
        });
        int res=0, n=properties.size();
        int maxi=properties[n-1][1];
        for(int i=n-2; i>=0; i--){
            if(properties[i][1]<maxi) res++;
            maxi=max(maxi,properties[i][1]);
        }
        return res;
    }
};