typedef pair<int,int> pii;
typedef long long ll;
int mod=1e9+7;
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        deque<pii> dq;
        int n=arr.size();
        ll res=0;
        arr.push_back(0);
        for(int i=0; i<=n; i++){
            if(!dq.empty() && arr[i]>=arr[dq.back().first]) dq.push_back({i, i});
            else{
                int pos=i;
                while(!dq.empty() && arr[i]<arr[dq.back().first]){
                    pos=dq.back().second;
                    res=(res+arr[dq.back().first]*1ll*(i-dq.back().first)*(dq.back().first-pos+1))%mod;
                    dq.pop_back();
                }
                dq.push_back({i,pos});
            }
        }
        return res;
    }
};