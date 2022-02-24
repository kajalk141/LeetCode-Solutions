int ans=0, cnt=0;

class Solution {
    bool isValid(int i, int j, int n, int m){
        return (i>=0 && i<n && j>=0 && j<m);
    }

    void dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<bool>>& vis){
        if(matrix[i][j]==0) return;
        if(vis[i][j]==1) return;
        vis[i][j]=1;
        cnt++;
        int n=matrix.size(), m=matrix[0].size();
        if(isValid(i,j-1,n,m)) dfs(i,j-1,matrix,vis);
        if(isValid(i,j+1,n,m)) dfs(i,j+1,matrix,vis);
        if(isValid(i-1,j,n,m)) dfs(i-1,j,matrix,vis);
        if(isValid(i+1,j,n,m)) dfs(i+1,j,matrix,vis);

    }
public:
    int maxAreaOfIsland(vector<vector<int>>& matrix) {
        ans=0;
        int n=matrix.size(), m=matrix[0].size(); 
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==1 && vis[i][j]==0){
                    cnt=0;
                    dfs(i,j,matrix,vis);
                    ans=max(ans,cnt);
                }
            }
        }
        return ans;
    }
};