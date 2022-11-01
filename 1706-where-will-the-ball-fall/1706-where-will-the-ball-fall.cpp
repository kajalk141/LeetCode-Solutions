class Solution {
public:
    int n, m;
    int dfs(int row, int col, vector<vector<int>>& grid){
        if(row==n) return col;
        if(col==0 && grid[row][col]==-1) return -1;
        if(col==m-1 && grid[row][col]==1) return -1;
        if(grid[row][col]==1){
            if(grid[row][col+1]==-1) return -1;
            else return dfs(row+1,col+1,grid);
        }
        else{
            if(grid[row][col-1]==1) return -1;
            else return dfs(row+1,col-1,grid);
        }
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        n=grid.size(); m=grid[0].size();
        vector<int> res;
        for(int i=0; i<m; i++){
            res.push_back(dfs(0,i,grid));
        }
        return res;
    }
};