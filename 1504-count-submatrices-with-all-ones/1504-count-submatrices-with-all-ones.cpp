class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n=mat.size(), m=mat[0].size(), cnt=0;
        for(int i=0; i<n; i++){
            vector<int> temp(m,1);
            for(int j=i; j<n; j++){
                for(int k=0; k<m; k++) temp[k]=temp[k] && mat[j][k];
                cnt+=helper(temp,m);
            }
        }
        return cnt;
    }
    int helper(vector<int> &temp, int m){
        int len=0, res=0;
        for(int i=0; i<m; i++){
            len=(temp[i]==0?0:len+1);
            res+=len;
        }
        return res;
    }
};