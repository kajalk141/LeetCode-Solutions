class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> in_degree(n,0);
        for(auto i:edges){
            in_degree[i[1]]++;
        }
        vector<int> res;
        for(int i=0; i<n; i++){
            if(in_degree[i]==0) res.push_back(i);
        }
        return res;
    }
};