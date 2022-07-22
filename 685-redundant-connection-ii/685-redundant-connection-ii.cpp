class Solution {
public:
    vector<int> par, size;
    int find(int a){
        if(par[a]==a) return a;
        return par[a]=find(par[a]);
    }
    bool merge(int a, int b){
        a=find(a);
        b=find(b);
        if(a==b) return true;
        if(size[a]<size[b]) swap(a,b);
        par[b]=a;
        size[a]+=size[b];
        return false;
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        par.assign(n+1,0);
        size.assign(n+1,0);
        for(int i=1; i<=n; i++){
            par[i]=i;
            size[i]=1;
        }
        vector<int> indeg(n+1,0);
        int node=-1;
        for(auto edge:edges){
            int u=edge[0], v=edge[1];
            indeg[v]++;
            if(indeg[v]==2) node=v;
        }
        if(node==-1){
            for(auto edge:edges){
                int u=edge[0], v=edge[1];
                if(merge(u,v)) return edge;
            }
        }
        else{
            int a=-1, b=-1;
            for(auto edge:edges){
                int u=edge[0], v=edge[1];
                if(v!=node) merge(u,v);
                else if(a==-1) a=u;
                else b=u;
            }
            if(find(a)==find(node)) return {a,node};
            return {b,node};
        }
        return {};
    }
};