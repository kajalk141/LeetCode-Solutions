class Solution {
public:
    int strStr(string text, string pattern) {
        int n=text.size(), m=pattern.size();
        
        if(n<m) return -1;
        if(m==0) return 0;
        
        int p=31, mod=1e9+9;
        vector<long long> p_pow(n);
        p_pow[0]=1;
        for(int i=1; i<(int)p_pow.size(); i++)
            p_pow[i]=(p_pow[i-1]*p)%mod;
        
        vector<long long> hash(n+1,0);
        for(int i=0; i<n; i++)
            hash[i+1]=(hash[i]+(text[i]-'a'+1)*p_pow[i])%mod;
        
        long long hash_pat=0;
        for(int i=0; i<m; i++)
            hash_pat=(hash_pat+(pattern[i]-'a'+1)*p_pow[i])%mod;
        
        for(int i=0; i<=n-m; i++){
            long long curr= (hash[i+m]-hash[i]+mod)%mod;
            if(curr==(hash_pat*p_pow[i])%mod)
                return i;
        }
        return -1;
    }
};