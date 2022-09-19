class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> mp;
        for(string path:paths){
            int i=0, n=path.size();
            string d="", content="", file="";
            while(path[i]!=' ') d.push_back(path[i++]);
            i++;
            for(; i<n; i++){
                while(i<n && path[i]!='(') file.push_back(path[i++]);
                i++;
                while(i<n && path[i]!=')') content.push_back(path[i++]);
                mp[content].push_back(d+"/"+file);
                content=""; file=""; i++;
            }
        }
        vector<vector<string>> res;
        for(auto x:mp){
            if((int)x.second.size()==1) continue;
            res.push_back(x.second);
        }
        return res;
    }
};
