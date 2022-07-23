class Solution {
public:
    int n, m;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n=matrix.size(); m=matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        int res=1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                res=max(res, rec(i,j,matrix,dp));
            }
        }
        return res;
    }
    
    int rec(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(dp[i][j]!=-1) return dp[i][j];
        int res=1;
        for(int x=-1; x<=1; x++){
            for(int y=-1; y<=1; y++){
                if(abs(x)==abs(y)) continue;
                int r=i+x, c=j+y;
                if(r<0||r>=n||c<0||c>=m) continue;
                if(matrix[i][j]>=matrix[r][c]) continue;
                res=max(res, 1+rec(r,c,matrix,dp));
            }
        }
        return dp[i][j]=res;
    }
};