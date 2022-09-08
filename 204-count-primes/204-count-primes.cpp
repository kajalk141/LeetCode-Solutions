class Solution {
public:
    
    int countPrimes(int n) {
        if(n==0) return 0;
        vector<bool> primes(n+1,1);
        primes[0]=primes[1]=0;
        for(int i=2; i*i<=n; i++){
            if(primes[i])
                for(int j=i*i; j<=n; j+=i)
                    primes[j]=0;
        }
        int cnt=0;
        for(int i=1; i<n; i++)
            cnt+= primes[i];
        
        return cnt;
    }
};