class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int res=0;
        for(auto x:accounts){
            int sum=0;
            for(auto i:x) sum+=i;
            res=max(res,sum);
        }
        return res;
    }
};