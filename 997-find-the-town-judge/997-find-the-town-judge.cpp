class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<set<int>> graph(n+1);
        for(auto i:trust){
            graph[i[0]].insert(i[1]);
        }
        int cnt=0, temp=-1;
        for(int i=1; i<=n; i++){
            int m=graph[i].size();
            if(m==0){
                cnt++;
                temp=i;
            }
        }
        if(cnt!=1) return -1;
        for(int i=1; i<=n; i++){
            int m=graph[i].size();
            if(m==0) continue;
            if(graph[i].find(temp)==graph[i].end()) return -1;
            
        }
        return temp;
    }
};