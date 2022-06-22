typedef pair<int,vector<int>> p;
class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        priority_queue<p, vector<p>, greater<p>> pq;
        int m=mat.size(), n=mat[0].size(), sum=0;
        
        for(int i=0; i<m; i++) sum+=mat[i][0];
        vector<int> temp(m,0);
        pq.push({sum,temp});
        set<vector<int>> s;
        s.insert(temp);
        
        while(!pq.empty() && k--){
            auto x=pq.top();
            pq.pop();
            int res=x.first;
            vector<int> v=x.second;
            if(k==0) return res;
            
            for(int i=0; i<m; i++){
                res=x.first;
                v=x.second;
                int j=v[i];
                res-=mat[i][j];
                if(j+1<n){
                    res+= mat[i][j+1];
                    v[i]=j+1;
                    if(s.find(v)==s.end()){
                        pq.push({res,v});
                        s.insert(v);
                    }
                }
            }
        }
        return 0;
    }
};