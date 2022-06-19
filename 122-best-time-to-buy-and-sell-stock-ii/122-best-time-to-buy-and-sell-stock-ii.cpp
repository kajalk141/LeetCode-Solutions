class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int amt=-1, res=0;
        for(int i=0; i<(int)prices.size(); i++){
            if(amt==-1) amt=prices[i];
            else{
                if(prices[i]>=amt) res+=prices[i]-amt;
                amt=prices[i];
            }
        }
        return res;
    }
};