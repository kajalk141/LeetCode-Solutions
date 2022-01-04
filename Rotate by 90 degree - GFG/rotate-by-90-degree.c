// { Driver Code Starts
//Initial Template for C



#include<stdio.h>

 // } Driver Code Ends
//User function Template for C


void rotate(int n,int a[][n])
{
    //code here
    int temp;
    for(int i=0; i<n/2; i++){
        for(int j=0; j<n; j++){
            temp=a[i][j];
            a[i][j]=a[n-i-1][j];
            a[n-i-1][j]=temp;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i; j++){
            temp=a[i][j];
            a[i][j]=a[n-1-j][n-1-i];
            a[n-1-j][n-1-i]=temp;
        }
    }
}

// { Driver Code Starts.

int main()
{
    int t;
    scanf("%d",&t); 
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int a[n][n];
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                scanf("%d",&a[i][j]);
        }
        rotate(n,a);
        for (int i = 0; i < n; ++i)
        {
            for(int j=0; j<n; j++)
                printf("%d ",a[i][j]);
            printf("\n");
        }
    }
    return 0;
}

  // } Driver Code Ends