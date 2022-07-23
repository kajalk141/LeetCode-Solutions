class Solution {
public:
    vector<vector<int>> paths;
    vector<int> path;
    int n;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n=graph.size();
        path.push_back(0);
        dfs(0,graph);
        return paths;
    }
    
    void dfs(int v, vector<vector<int>>& graph){
        if(v==n-1){
            paths.push_back(path);
            return;
        }
        for(int to:graph[v]){
            path.push_back(to);
            dfs(to,graph);
            path.pop_back();
        }
    }
};