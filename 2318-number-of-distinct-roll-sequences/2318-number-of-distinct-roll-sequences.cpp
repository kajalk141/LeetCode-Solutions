typedef long long ll;
int mod=1e9+7;
class Solution {
public:
    vector<vector<int>> next={{1,2,3,4,5,6}, {1,2,3,4,5,6}, {1,2,3,5}, {1,2,3,4,5}, {1,3,4,5}, {1,2,3,4,5,6}, {1,5,6}};
    
    int rec(int i, int p, int pp, int n, vector<vector<vector<int>>> &dp){ 
        //ith roll, previous roll (i-1)th outcome, previous to previous roll outcome, total rolls allowed
        if(i>n) return 1; //previous roll outcome is valid
        if(dp[i][p][pp]!=-1) return dp[i][p][pp];
        int res=0;
        for(int c:next[p]){
            if(c==p || c==pp) continue;
            res=(res+rec(i+1,c,p,n,dp))%mod; //ith roll results in 'c' as outcome
        }
        return dp[i][p][pp]=res;
    }
    
    int distinctSequences(int n) {
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(7,vector<int>(7,-1)));
        return rec(1,0,0,n,dp)%mod;
    }
};