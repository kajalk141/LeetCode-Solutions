class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        for(char c:s){
            if(st.empty() || st.top().first!=c) st.push({c,1});
            else st.push({c,st.top().second+1});
            if(st.top().second==k){
                char temp=st.top().first;
                while(!st.empty() && st.top().first==temp) st.pop();
            }
        }
        int n=st.size();
        for(int i=n-1; i>=0; i--){
            s[i]=st.top().first;
            st.pop();
        }
        s.erase(n);
        return s;
    }
};