typedef pair<int,int> pii;
typedef long long ll;
int mod=1e9+7;
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pii> v(n);
        for(int i=0; i<n; i++) 
            v[i]={efficiency[i],speed[i]};
        sort(v.rbegin(), v.rend());
        ll total=0, minE, res=0;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0; i<k; i++){
            total+= v[i].second;
            minE=v[i].first;
            res=max(res, total*minE);
            pq.push(v[i].second);
        }
        for(int i=k; i<n; i++){
            if(v[i].second > pq.top()){
                total=total-pq.top()+v[i].second;
                minE=v[i].first;
                res=max(res,total*minE);
                pq.pop();
                pq.push(v[i].second);
            }
        }
        return res%mod;
    }
};