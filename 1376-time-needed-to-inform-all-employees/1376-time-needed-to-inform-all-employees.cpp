#define pii pair<int,int>
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> tree(n);
        for(int i=0; i<n; i++){
            if(i==headID) continue;
            tree[manager[i]].push_back(i);
        }
        int time;
        queue<pii> q;
        q.push({headID,0});
        while(!q.empty()){
            int sz=q.size(), temp=0;
            for(int i=0; i<sz; i++){
                int node=q.front().first, past=q.front().second; q.pop();
                time=max(time, past+informTime[node]);
                for(int child:tree[node]){
                    q.push({child, past+informTime[node]});
                }
            }
        }
        return time;
    }
    
};