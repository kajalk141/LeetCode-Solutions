class Solution {
public:
    int peri,n,m;
    int islandPerimeter(vector<vector<int>>& grid) {
        n=grid.size(); m=grid[0].size(); peri=0;
        bool flag=1;
        for(int i=0; flag && i<n; i++){
            for(int j=0; flag && j<m; j++){
                if(grid[i][j]==1){
                    dfs(i,j,grid);
                    flag=0;
                }
            }
        }
        return peri;
    }
    
    void dfs(int i, int j, vector<vector<int>> &grid){
        grid[i][j]=2;
        for(int x=-1; x<=1; x++){
            for(int y=-1; y<=1; y++){
                if(abs(x)==abs(y)) continue;
                int r=i+x, c=j+y;
                if(r<0||r>=n||c<0||c>=m||grid[r][c]==0){
                    peri++;
                    continue;
                }
                if(grid[r][c]==1) dfs(r,c,grid);
            }
        }
    }
};