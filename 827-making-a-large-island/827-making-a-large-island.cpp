class Solution {
public:
    int n,m;
    unordered_map<int,int> mp;
    int largestIsland(vector<vector<int>>& grid) {
        n=grid.size(); m=grid[0].size();
        int col=2;
        int res=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    dfs(i,j,grid,col);
                    res=max(res,mp[col]);
                    col++;
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]!=0) continue;
                int curr=1;
                set<int> colors;
                for(int x=-1; x<=1; x++){
                    for(int y=-1; y<=1; y++){
                        if(abs(x)==abs(y)) continue;
                        int r=i+x, c=j+y;
                        if(r<0||r>=n||c<0||c>=m||grid[r][c]==0) continue;
                        colors.insert(grid[r][c]);
                    }
                }
                for(int x:colors) curr+=mp[x];
                res=max(res,curr);
            }
        }
        return res;
    }
    
    void dfs(int i, int j, vector<vector<int>> &grid, int &col){
        grid[i][j]=col;
        mp[col]++;
        for(int x=-1; x<=1; x++){
            for(int y=-1; y<=1; y++){
                if(abs(x)==abs(y)) continue;
                int r=i+x, c=j+y;
                if(r<0||r>=n||c<0||c>=m) continue;
                if(grid[r][c]!=1) continue;
                dfs(r,c,grid,col);
            }
        }
    }
};