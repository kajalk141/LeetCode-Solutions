class Solution {
    void dfs(int v, vector<vector<int>>& graph, vector<int>& comp, int cnt){
        if(comp[v]==cnt) return;
        comp[v]=cnt;
        for(auto i:graph[v]){
            dfs(i,graph,comp,cnt);
        }
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        int cnt=0;
        vector<vector<int>> graph(n);
        for(auto i:edges){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        vector<int> comp(n,0);
        for(int i=0; i<n; i++){
            if(comp[i]==0){
                cnt++;
                dfs(i,graph,comp,cnt);
            }
        }
        if(comp[source]==comp[destination]) return true;
        return false;
    }
};