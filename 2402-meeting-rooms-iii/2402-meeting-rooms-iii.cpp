typedef long long ll;
typedef pair<ll,ll> pii;
class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b){
        return a[0]<b[0];
    }
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end(), comp);
        priority_queue<pii,vector<pii>,greater<pii>> taken;
        priority_queue<int,vector<int>,greater<int>> free;
        int m=meetings.size();
        for(int i=0; i<n; i++)
            free.push(i);
        vector<int> freq(n,0);
        for(int i=0; i<m; i++){
            while(!taken.empty() && taken.top().first<=meetings[i][0]){
                free.push(taken.top().second);
                taken.pop();
            }
            int duration=meetings[i][1]-meetings[i][0];
            if(free.empty()){
                taken.push({taken.top().first+duration,taken.top().second});
                freq[taken.top().second]++;
                taken.pop();
            }else{
                freq[free.top()]++;
                taken.push({meetings[i][1],free.top()});
                free.pop();
            }
        }
        int maxF=0, res;
        for(int i=0; i<n; i++){
            if(freq[i]>maxF){
                maxF=freq[i];
                res=i;
            }        
        }
        return res;
    }
};