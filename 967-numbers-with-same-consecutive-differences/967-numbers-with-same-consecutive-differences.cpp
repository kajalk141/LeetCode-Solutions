class Solution {
public:
    vector<int> res;
    vector<int> numsSameConsecDiff(int n, int k) {
        string curr="";
        for(int i=1; i<=9; i++){
            dfs(i,n,k,curr);
        }
        return res;
    }
    
    void dfs(int digit, int n, int k, string &curr){
        if(digit<0||digit>9) return;
        curr.push_back(digit+'0'); //
        if(n-1>0){
            dfs(digit+k,n-1,k,curr);
            if(k!=0) dfs(digit-k,n-1,k,curr);
        }else{
            res.push_back(stoi(curr));
        }
        curr.pop_back();
    }
};
