class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1,0);
        for(int i=1; i<=n; i++){
            if(i&(i-1)==0) dp[i]=1;
            else{
                int temp=log2(i);
                temp=pow(2,temp);
                dp[i]+= 1+dp[i-temp];
            }
        }
        return dp;
        
    }
};