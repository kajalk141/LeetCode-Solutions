// { Driver Code Starts
//Initial Template for C

#include <stdio.h>


 // } Driver Code Ends
//User function Template for C

// A[]: input array
// N: input array
//Function to sort the binary array.
void binSort(int A[], int N)
{
   //Your code here
   
   /**************
    * No need to print the array
    * ************/
    int zero=0, one=0;
   for(int i=0; i<N; i++)
   {
       if(A[i]==0) zero++;
       else one++;
   }
   int l=0, r=N-1;
   while(l<zero && r>=zero)
   {
       if(A[l]==1)
       {
           if(A[r]==0){
               int temp=A[l];
               A[l]=A[r];
               A[r]=temp;
               l++; r--;
           }
           else r--;
       }
       else l++;
   }
}

// { Driver Code Starts.

int main() {
	int T;
	scanf("%d", &T);
	// Input the number of testcases
	while(T--)
	{
	    int N;
	    scanf("%d", &N); //Input size of array N
	    int A[N]; 
	    
	    for(int i = 0; i  < N; i++)
	      scanf("%d", &A[i]);
	      
	    binSort(A,N);
	    
	    for(int i = 0; i  < N; i++)
	        printf("%d ", A[i]);
	      
	    printf("\n");
	}
	return 0;
}  // } Driver Code Ends