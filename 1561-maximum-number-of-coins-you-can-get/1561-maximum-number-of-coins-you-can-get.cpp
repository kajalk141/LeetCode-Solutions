class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int n=(int)piles.size()/3;
        int res=0, i=3*n-2;
        while(n--){
            res+=piles[i];
            i-=2;
        }
        return res;
    }
};