class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn=prices[0], mx=-1, profit=0;
        for(int i=1; i<prices.size(); i++){
            if(prices[i]>=mx) mx=prices[i];
            else{
                profit+= max(0, mx-mn);
                mn=prices[i]; mx=-1;
            }
            mn=min(mn,prices[i]);
        }
        profit+= max(0, mx-mn);
        return profit;
    }
};