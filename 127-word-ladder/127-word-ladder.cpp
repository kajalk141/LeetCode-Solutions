class Solution {
public:
    int ladderLength(string begin, string end, vector<string>& List) {
        map<string, set<string>> mp;
        for(int i=0; i<(int)begin.size(); i++){
            string str=begin.substr(0,i)+'*'+begin.substr(i+1);
            mp[str].insert(begin);
        }
        for(string word:List){
            for(int i=0; i<(int)word.size(); i++){
                string str=word.substr(0,i)+'*'+word.substr(i+1);
                mp[str].insert(word);
            }
        }
        map<string, bool> visited;
        queue<string> q;
        int len=0;
        visited[begin]=1;
        q.push(begin);
        while(!q.empty()){
            len++;
            int sz=q.size();
            for(int i=0; i<sz; i++){
                string word=q.front();
                q.pop();
                if(word==end) return len;
                for(int c=0; c<(int)word.size(); c++){
                    string str=word.substr(0,c)+'*'+word.substr(c+1);
                    for(string s:mp[str]){
                        if(visited[s]==1) continue;
                        visited[s]=1;
                        q.push(s);
                    }
                }
            }
        }
        return 0;
    }
};