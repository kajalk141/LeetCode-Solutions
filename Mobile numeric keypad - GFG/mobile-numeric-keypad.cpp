//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{


	public:
    vector<vector<int>> moves={{8},{2,4},{1,3,5},{2,6},{1,5,7},{2,4,6,8},{3,5,9},{4,8},{5,7,9,0},{6,8}};
	long long getCount(int N)
	{
		// Your code goes here
		vector<vector<long long>> dp(10,vector<long long>(N+1,-1));
		long long res=0;
		for(int i=0; i<=9; i++)
		res+= rec(i,N,dp);
		return res;
	}
	
	long long rec(int curr, int N, vector<vector<long long>> &dp){
	    if(N==1) return 1;
	    if(dp[curr][N]!=-1) return dp[curr][N];
	    long long res=rec(curr,N-1,dp);;
	    int n=moves[curr].size();
	    for(int i=0; i<n; i++)
	    res+= rec(moves[curr][i],N-1,dp);
	    return dp[curr][N]=res;
	}


};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.getCount(n) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends