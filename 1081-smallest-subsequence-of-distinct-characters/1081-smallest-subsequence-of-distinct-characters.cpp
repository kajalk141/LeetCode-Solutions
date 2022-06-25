class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last(26,-1);
        vector<bool> seen(26,0);
        int n=s.size();
        stack<char> st;
        string res="";
        for(int i=0; i<n; i++) last[s[i]-'a']=i;
        for(int i=0; i<n; i++){
            if(seen[s[i]-'a']==1) continue;
            seen[s[i]-'a']=1;
            while(!st.empty() && s[i]<st.top() && last[st.top()-'a']>i){
                seen[st.top()-'a']=0;
                st.pop();
                res.pop_back();
            }
            st.push(s[i]);
            res+= s[i];
        }
        return res;
    }
};