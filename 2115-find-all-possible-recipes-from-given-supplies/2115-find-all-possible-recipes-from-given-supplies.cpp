class Solution {
    void dfs(int v, vector<vector<int>>& graph, vector<int>& vis){
        vis[v]=1;
        bool loop=false, can=true;
        for(int child:graph[v]){
            if(vis[child]==0) dfs(child,graph,vis);
            if(vis[child]!=2) can=false;
        }
        if((int)graph[v].size()==0 && vis[v]!=2) can=false;
        if(can) vis[v]=2;
    }
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        map<string,int> mp;
        int cnt=0;
        for(string s:recipes){
            mp[s]=cnt;
            cnt++;
        }
        for(auto i:ingredients){
            for(string s:i){
                if(mp.find(s)!=mp.end()) continue;
                mp[s]=cnt;
                cnt++;
            }
        }
        for(string s:supplies){
            if(mp.find(s)!=mp.end()) continue;
            mp[s]=cnt;
            cnt++;
        }
        vector<vector<int>> graph(cnt);
        for(int i=0; i<recipes.size(); i++){
            for(int j=0; j<ingredients[i].size(); j++){
                graph[mp[recipes[i]]].push_back(mp[ingredients[i][j]]);
            }
        }
        vector<int> vis(cnt,0);
        for(string s:supplies){
            vis[mp[s]]=2;
        }
        for(auto s:recipes){
            if(vis[mp[s]]==0) dfs(mp[s],graph,vis);
        }
        vector<string> res;
        for(auto s:recipes){
            if(vis[mp[s]]==2) res.push_back(s);
        }
        return res;
    }
};