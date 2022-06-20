typedef long long ll;
class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<ll> res;
        if(num%3!=0) return res;
        ll n=num/3;
        res.push_back(n-1);
        res.push_back(n);
        res.push_back(n+1);
        return res;
        
    }
};