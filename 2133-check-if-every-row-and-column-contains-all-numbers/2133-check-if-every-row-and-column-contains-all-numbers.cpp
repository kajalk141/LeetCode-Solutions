class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<bool> check(n,false);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++) check[j]=false;
            for(int j=0; j<n; j++) check[matrix[i][j]-1]=true;
            for(int j=0; j<n; j++) if(!check[j]) return false;
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++) check[j]=false;
            for(int j=0; j<n; j++) check[matrix[j][i]-1]=true;
            for(int j=0; j<n; j++) if(!check[j]) return false;
        }
        return true;
    }
};