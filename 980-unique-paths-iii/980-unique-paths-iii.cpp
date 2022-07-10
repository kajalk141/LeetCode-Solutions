class Solution {
public:
    int n, m, travel=1, res=0;
    bool check(int i, int j, vector<vector<int>>& grid){
        if(i<0 || i>=n || j<0 || j>=m) return 0;
        if(grid[i][j]<0) return 0;
        return 1;
    }
        
    int uniquePathsIII(vector<vector<int>>& grid) {
        n=grid.size(); m=grid[0].size();
        int r,c;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==0) travel++;
                if(grid[i][j]==1){
                    r=i; c=j;
                }
            }
        }
        rec(r,c,grid);
        return res;
    }
    
    void rec(int i, int j, vector<vector<int>>& grid){
        if(!check(i,j,grid)) return;
        if(grid[i][j]==2){
            if(travel==0) res++;
            return;
        }
        grid[i][j]=-1;
        travel--;
        rec(i+1,j,grid);
        rec(i-1,j,grid);
        rec(i,j+1,grid);
        rec(i,j-1,grid);
        grid[i][j]=0;
        travel++;
    }
};