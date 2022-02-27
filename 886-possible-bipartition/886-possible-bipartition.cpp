class Solution {
    bool dfs(int v, vector<vector<int>>& graph, vector<int>& vis, int color){
        vis[v]=color;
        bool has=true;
        for(auto child:graph[v]){
            if(vis[child]==-1) has=has && dfs(child,graph,vis,color^1);
            if(vis[child]==vis[v]) return false;
        }
        return has;
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n+1);
        for(auto i:dislikes){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        vector<int> vis(n+1,-1);
        bool has=true;
        for(int i=1; i<=n; i++){
            if(vis[i]==-1){
                has=has && dfs(i,graph,vis,0);
            }
        }
        return has;
    }
};