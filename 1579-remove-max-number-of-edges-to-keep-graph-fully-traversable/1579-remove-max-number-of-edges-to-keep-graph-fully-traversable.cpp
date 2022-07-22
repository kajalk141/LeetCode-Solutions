class UnionFind {
    vector<int> par; 
    int cc;
public:
    UnionFind(int n) {
	    cc = n;
        for (int i=0; i<=n; i++) {
            par.push_back(i);
        }
    }
    bool merge(int a, int b) {       
        a=find(a);
        b=find(b);
        if(a==b) return 0;
        par[b]=a;
        cc--;
        return 1;
    }
    int find(int a) {
        if(a==par[a]) return a;
        return par[a]=find(par[a]);
    }
    bool united() {
        return cc == 1;
    }
};

class Solution {
    
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(), edges.end(), [] (auto &a, auto &b) { return a[0] > b[0]; });
        
        int edgesAdded = 0; 
        
        UnionFind bob(n), alice(n); 
        
        for (auto &edge: edges) { 
            int type = edge[0], one = edge[1], two = edge[2];
            switch(type) {
                case 3:
                    edgesAdded += (bob.merge(one, two) | alice.merge(one, two));
                    break;
                case 2:
                    edgesAdded += bob.merge(one, two);
                    break;
                case 1:
                    edgesAdded += alice.merge(one, two);
                    break;
            }
        }
        
        return (bob.united() && alice.united()) ? (edges.size()-edgesAdded) : -1; 
    }
};