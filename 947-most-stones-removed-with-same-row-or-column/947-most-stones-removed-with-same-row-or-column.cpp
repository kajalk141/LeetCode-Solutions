class Solution {
public:
    vector<int> par;
     int find(int a){
        if(a==par[a]) return a;
        return par[a]=find(par[a]);
    }
    void merge(int a, int b){
        a=find(a);
        b=find(b);
        par[b]=a;
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        par.assign(n,0);
        for(int i=0; i<n; i++){
            par[i]=i;
        }
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(stones[i][0]==stones[j][0]||stones[i][1]==stones[j][1])
                    merge(i,j);
            }
        }
        int res=0;
        for(int i=0; i<n; i++){
            if(i==find(i)) res++;
        }
        return n-res;
    }
};