// class  cmp{
// public:
//     bool operator() (string &a, string &b){
//         return a.size()<b.size();
//     }
// };
class Solution {
    int rec(int i, int j, string &s, string &t, vector<vector<int>> &dp){
        if(i<0||j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        if(s[i]==t[j]) ans=1+rec(i-1,j-1,s,t,dp);
        else ans=max(rec(i-1,j,s,t,dp),rec(i,j-1,s,t,dp));
        return dp[i][j]=ans;
    }
public:
    int longestStrChain(vector<string>& words) {
        int len=words.size();
        sort(words.begin(),words.end(),[](string &a, string &b){
            return a.size()<b.size();
        });
        int res=0;
        vector<int> lis(len,1);
        for(int i=0; i<len; i++){
            for(int j=0; j<i; j++){
                int n=words[i].size(), m=words[j].size();
                if(n-m!=1) continue;
                vector<vector<int>> dp(n,vector<int>(m,-1));
                if(rec(n-1,m-1,words[i],words[j],dp)==m){
                    lis[i]=max(lis[i],lis[j]+1);
                }
            }
            res=max(res,lis[i]);
        }
        return res;
    }
};