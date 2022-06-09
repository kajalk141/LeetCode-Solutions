class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        rec(1,n,k,temp);
        return res;
    }
    
    void rec(int i, int n, int k, vector<int> &temp){
        for(int j=i; j<=n; j++){
            if((int)temp.size()<k){
                temp.push_back(j);
                rec(j+1,n,k,temp);
                temp.pop_back();
            }
        }
        if((int)temp.size()==k) res.push_back(temp);
        return;
    }
};