typedef long long ll;
class Solution {
public:
    ll calculateHash(string s, vector<ll> &p, ll m) {
        ll hash = 0;
        for (int i = 0; i < s.length(); i++) {
            hash = (hash + (ll)(s[i] - 'a' + 1) * p[i]) % m;
        }
        return hash;
    }
    string subStrHash(string s, int power, int mod, int k, int hashValue) {
        int n=s.size();
        vector<ll> p(n);
        p[0]=1;
        for(int i=1; i<n; i++) p[i]=(p[i-1]*power)%mod;
        
        vector<ll> hash(n+1,0);
        for(int i=0; i<n; i++) hash[i+1]=(hash[i]+(ll)(s[i]-'a'+1)*p[i])%mod;
        long long h=hashValue % mod;
        for(int i=0; i+k-1<n; i++){
            ll curr=(hash[i+k]+mod-hash[i])%mod;
            if(curr==(h*p[i])%mod){
                if(calculateHash(s.substr(i,k),p,mod)==h)
                    return s.substr(i,k);
            }
        }
        return "";
    }
};