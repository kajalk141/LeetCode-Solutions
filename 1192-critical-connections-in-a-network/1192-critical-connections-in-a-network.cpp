class Solution {
public:
    vector<vector<int>> bridges;
    vector<int> in, low;
    int time=0;
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        in.assign(n,-1);
        low.assign(n,-1);
        time=0;
        vector<vector<int>> graph(n);
        for(auto edge:connections){
            int u=edge[0], v=edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        dfs(0,-1,graph);
        return bridges;
    }
    
    void dfs(int v, int p, vector<vector<int>> &graph){
        in[v]=low[v]=time++;
        for(int neigh:graph[v]){
            if(neigh==p) continue;
            if(in[neigh]!=-1){
                low[v]=min(low[v], low[neigh]);
            }else{
                dfs(neigh,v,graph);
                low[v]=min(low[v], low[neigh]);
                if(low[neigh]>in[v]){
                    bridges.push_back({v,neigh});
                }
            }
        }
    }
};