class Solution {
    void dfs(int i, int n, vector<vector<int>>& matrix, vector<bool>& vis){
        if(vis[i]==1) return;
        vis[i]=1;
        for(int c=0; c<n; c++){
            if(matrix[i][c]==1 && vis[c]==0){
                dfs(c,n,matrix,vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& matrix) {
        int n=matrix.size(), cnt=0; 
        vector<bool> vis(n,0);
        for(int i=0; i<n; i++){
            if(vis[i]==0){
                cnt++;
                dfs(i,n,matrix,vis);
            }
        }
        return cnt;
    }
};