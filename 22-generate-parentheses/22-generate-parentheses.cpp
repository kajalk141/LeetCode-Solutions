class Solution {
public:
    vector<string> res;
    string temp="";
    vector<string> generateParenthesis(int n) {
        rec(0,0,0,n);
        return res;
    }
    
    void rec(int i, int curr, int cnt, int n){
        if(i==2*n){
            if(curr==0) res.push_back(temp);
            return;
        }
        // if total no. of open brackets less than n
        if(cnt<n){
            temp.push_back('(');
            rec(i+1,curr+1,cnt+1,n);
            temp.pop_back();
        }
        // if there are open brackets
        if(curr>0){
            temp.push_back(')');
            rec(i+1,curr-1,cnt,n);
            temp.pop_back();
        }
    }
};