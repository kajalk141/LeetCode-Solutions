class Solution {
    void dfs(int v,vector<vector<int>> &tgraph, vector<bool>& vis, vector<int>& temp){
        vis[v]=true;
        for(auto neigh:tgraph[v]){
            if(vis[neigh]==true) continue;
            temp.push_back(neigh);
            dfs(neigh,tgraph,vis,temp);
        }
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> tgraph(n);
        for(auto i:edges){
            tgraph[i[1]].push_back(i[0]);
        }
        vector<vector<int>> res(n);
        for(int i=0; i<n; i++){
            vector<bool> vis(n,false);
            dfs(i, tgraph, vis, res[i]);
            sort(res[i].begin(), res[i].end());
        }
        return res;
    }
};