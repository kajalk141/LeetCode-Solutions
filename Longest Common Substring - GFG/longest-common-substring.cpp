// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    int res=0;
    int rec(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        if(i<0||j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        if(s1[i]==s2[j]){
            ans=1+rec(i-1,j-1,s1,s2,dp);
        }
        res=max(res,ans);
        res=max(res,rec(i,j-1,s1,s2,dp)); 
        res=max(res,rec(i-1,j,s1,s2,dp));
        return dp[i][j]=ans;
    }
    public:
    
    int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        // your code here
        vector<vector<int>> dp(n,vector<int>(m,-1));
        rec(n-1,m-1,s1,s2,dp);
        return res;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends