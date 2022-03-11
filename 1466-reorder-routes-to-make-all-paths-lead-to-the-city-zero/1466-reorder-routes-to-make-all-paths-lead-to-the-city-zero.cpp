class Solution {
    void dfs(int v, vector<vector<int>>& graph, vector<bool>& vis, map<int,vector<int>>& mp, int &res){
        vis[v]=true;
        for(auto neigh:graph[v]){
            if(vis[neigh]) continue;
            auto vec=mp[neigh];
            if(find(vec.begin(),vec.end(),v)==vec.end()) res+=1;
            dfs(neigh,graph,vis,mp,res);
        }
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        int res=0;
        map<int,vector<int>> mp;
        vector<vector<int>> graph(n);
        for(auto i:connections){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
            mp[i[0]].push_back(i[1]);
        }
        vector<bool> vis(n,false);
        dfs(0,graph,vis,mp,res);
        return res;
    }
};