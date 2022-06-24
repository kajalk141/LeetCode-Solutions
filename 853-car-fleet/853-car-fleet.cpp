typedef pair<int,double> pii; //distance,time
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        // sort(positions.begin(), positions.end(), greater<int>());
        priority_queue<pii> pq;
        for(int i=0; i<n; i++){
            pq.push({position[i], (target-position[i])/(double)speed[i]});
        }
        int res=0;
        while(!pq.empty()){
            auto x=pq.top();
            pq.pop();
            while(!pq.empty() && pq.top().second<=x.second) pq.pop();
            res++;
        }
        return res;
    }
};