class Solution {
    bool isValid(int r, int c, int n, int m){
        return (r>=0 && r<n && c>=0 && c<m);
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        queue<pair<int,int>> q;
        int tot=0, rot=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]!=0) tot++;
                if(grid[i][j]==2) q.push({i,j});
            }
        }
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        int time=0;
        while(!q.empty()){
            int cnt=q.size();
            rot+=cnt;
            for(int i=0; i<cnt; i++){
                int x=q.front().first, y=q.front().second;
                q.pop();
                for(int j=0; j<4; j++){
                    int nx=x+dx[j], ny=y+dy[j];
                    if(nx<0||nx>=n||ny<0||ny>=m||grid[nx][ny]!=1) continue;
                    grid[nx][ny]=2;
                    q.push({nx,ny});
                }
            }
            if(!q.empty()) time++;
        }
        return rot==tot?time:-1;
    }
};