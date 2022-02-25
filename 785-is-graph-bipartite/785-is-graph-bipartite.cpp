class Solution {
    bool dfs(int v, vector<vector<int>>& graph, vector<int>& color, int col){
        color[v]=col;
        bool flag=true;
        for(auto i:graph[v]){
            if(color[i]==-1) flag=flag && dfs(i,graph, color, col^1);
            else if(color[i]==col) return false; 
        }
        return flag;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        bool flag=true;
        for(int i=0; i<n; i++){
            if(color[i]==-1){
                flag=flag && dfs(i,graph,color,0);
            }
        }
        return flag;
    }
};