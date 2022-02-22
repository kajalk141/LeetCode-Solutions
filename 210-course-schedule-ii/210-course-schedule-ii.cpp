class Solution {
    bool cycle(int v, vector<vector<int>>& graph, vector<int>& vis, vector<int>&res){
        vis[v]=1;
        bool loop=false;
        for(auto neigh:graph[v]){
            if(vis[neigh]==1) return true;
            if(vis[neigh]==0) loop |= cycle(neigh,graph,vis,res);
        }
        vis[v]=2;
        res.push_back(v);
        return loop;
    }
public:
    vector<int> findOrder(int num, vector<vector<int>>& pre) {
        vector<vector<int>> graph(num); //[1,0] ---> graph[1]={0};
        for(auto i:pre){
            graph[i[0]].push_back(i[1]);
        }
        vector<int> vis(num,0), res;
        bool loop=false;
        //0->not visited, 1->being processed, 2->completely visited
        for(int i=0; i<num; i++){
            if(vis[i]==0) loop |= cycle(i,graph,vis,res);
            
        }
        if(loop) res.clear();
        return res;
    }
};