// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        // your code here
        sort(arr, arr+N);
        int n=arr[0].size(), m=arr[N-1].size();
        string res="";
        for(int i=0; i<min(n,m); i++)
        {
            if(arr[0][i]==arr[N-1][i])
               res+=arr[0][i];
            else break;
        }
        if(int(res.size())==0) res="-1";
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends