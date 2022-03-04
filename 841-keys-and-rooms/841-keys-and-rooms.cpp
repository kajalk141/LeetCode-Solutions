class Solution {
    void dfs(int v, vector<vector<int>> &rooms, vector<bool> &vis){
        if(vis[v]==true) return;
        vis[v]=true;
        for(auto neigh:rooms[v]){
            if(vis[neigh]) continue;
            dfs(neigh,rooms,vis);
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool> vis(n,false);
        dfs(0,rooms,vis);
        bool res=true;
        for(auto i:vis) res=res&&i;
        return res;
    }
};