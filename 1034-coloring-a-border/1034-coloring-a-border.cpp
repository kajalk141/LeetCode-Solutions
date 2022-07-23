class Solution {
public:
    int n,m;
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        n=grid.size(); m=grid[0].size();
        dfs(row,col,grid[row][col],grid);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]<0) grid[i][j]=color;
            }
        }
        return grid;
    }
    void dfs(int i, int j, int prev, vector<vector<int>> &grid){
        grid[i][j]=-prev;
        int cnt=0;
        for(int x=-1; x<=1; x++){
            for(int y=-1; y<=1; y++){
                if(abs(x)==abs(y)) continue;
                int r=i+x, c=j+y;
                if(r<0||r>=n||c<0||c>=m||abs(grid[r][c])!=prev) continue;
                cnt++;
                if(grid[r][c]==prev) dfs(r,c,prev,grid);
            }
        }
        if(cnt==4) grid[i][j]=prev;
    }
};