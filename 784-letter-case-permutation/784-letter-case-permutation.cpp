class Solution {
public:
    vector<string> res;
    int n;
    vector<string> letterCasePermutation(string s) {
        n=s.size();
        string curr="";
        dfs(0,s,curr);
        return res;
    }
    
    void dfs(int i, string s, string &curr){
        if(i==n){
            res.push_back(curr);
            return;
        }
        curr.push_back(s[i]);
        dfs(i+1,s,curr);
        curr.pop_back();
        if(s[i]>='a' && s[i]<='z'){
            curr.push_back(s[i]-32);
            dfs(i+1,s,curr);
            curr.pop_back();
        }
        else if(s[i]>='A' && s[i]<='Z'){
            curr.push_back(s[i]+32);
            dfs(i+1,s,curr);
            curr.pop_back();
        }
    }
};