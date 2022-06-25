class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n=arr.size();
        int l=-1, r;
        for(int i=0; i<n-1; i++){
            if(arr[i]>arr[i+1]){
                l=i;
                break;
            }
        }
        if(l==-1) return 0;
        for(int i=n-1; i>=0; i--){
            if(arr[i]<arr[i-1]){
                r=i;
                break;
            }
        }
        int i=0, j=r, res=min(r,n-l-1);
        while(i<=l && j<n){
            if(arr[j]>=arr[i]){
                res=min(res, j-i-1); //keep both index elements
                i++;
            }
            else{
                res=min(res, j-i); //must kick one of them
                j++;
            }
        }
        return res;
    }
};