typedef pair<int,int> pii;

class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int n=apples.size();
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        int day=1, i=0, apple=0;
        while(i<n || !pq.empty()){
            if(i<n){
                if(apples[i]!=0){
                    pq.push({i+days[i]+1,apples[i]});
                }
                i++;
            }
            while(!pq.empty() && pq.top().first<=day) pq.pop();
            day++;
            if(pq.empty()) continue;
            pii temp=pq.top();
            pq.pop();
            if(temp.second>1) pq.push({temp.first,temp.second-1});
            apple++;
        }
        return apple;
    }
};