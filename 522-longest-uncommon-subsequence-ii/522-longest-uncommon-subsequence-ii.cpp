class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        int n=strs.size();
        unordered_map<string, int> mp;
        for(string s:strs){
            string t="";
            generate(0,s,t,mp);
        }
        int len=-1;
        for(auto x:mp){
            if(x.second==1){
                len=max(len,(int)x.first.size());
            }
        }
        return len;
    }
    void generate(int i,string &s, string &t, unordered_map<string, int> &mp){
        if(i==(int)s.size()){
            return;
        }
        for(int j=i; j<s.size(); j++){
            t+=s[j];
            mp[t]++;
            generate(j+1,s,t,mp);
            t.pop_back();
        }
    }
};