class Solution {
public:
    int n,m;
    int shortestBridge(vector<vector<int>>& grid) {
        n=grid.size(); m=grid[0].size();
        bool flag=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    dfs(i,j,grid);
                    flag=1;
                    break;
                }
            }
            if(flag) break;
        }
        queue<pair<int,int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2) 
                    q.push({i,j});
            }
        }
        int res=0;
        while(!q.empty()){
            int sz=q.size();
            for(int s=0; s<sz; s++){
                int i=q.front().first, j=q.front().second;
                q.pop();
                for(int x=-1; x<=1; x++){
                    for(int y=-1; y<=1; y++){
                        if(abs(x)==abs(y)) continue;
                        int r=i+x, c=j+y;
                        if(r<0||r>=n||c<0||c>=m) continue;
                        if(grid[r][c]==1) return res;
                        if(grid[r][c]==2) continue; 
                        grid[r][c]=2;
                        q.push({r,c});
                    }
                }
            }
            res++;
        }
        return res;
    }
    
    void dfs(int i, int j, vector<vector<int>> &grid){
        grid[i][j]=2;
        for(int x=-1; x<=1; x++){
            for(int y=-1; y<=1; y++){
                if(abs(x)==abs(y)) continue;
                int r=i+x, c=j+y;
                if(r<0||r>=n||c<0||c>=m) continue;
                if(grid[r][c]!=1) continue;
                dfs(r,c,grid);
            }
        }
    }
};