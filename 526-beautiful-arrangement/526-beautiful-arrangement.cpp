class Solution {
public:
    int countArrangement(int n) {
        int mask=0; //0 means available
        return rec(1,mask,n);
    }
    
    int rec(int i, int mask, int n){
        if(i==n+1) return 1;
        int cnt=0;
        for(int j=1; j<=n; j++){
            if((mask&(1<<j))!=0) continue; //jth number is not available
            if(i%j==0||j%i==0) cnt+= rec(i+1,mask^(1<<j),n);
        }
        return cnt;
    }
};