typedef long long ll;
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        ll sum=0;
        int neg=INT_MAX, cnt=0;
        int n=matrix.size(), m=matrix[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                sum+= abs(matrix[i][j]);
                if(matrix[i][j]<0) cnt++;
                neg=min(neg,abs(matrix[i][j]));
            }
        }
        if(cnt%2==0) return sum;
        return sum-2*neg;
    }
};