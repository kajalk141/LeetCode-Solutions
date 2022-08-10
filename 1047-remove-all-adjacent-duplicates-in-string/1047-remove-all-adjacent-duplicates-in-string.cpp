class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(char c:s){
            if(!st.empty() && st.top()==c) st.pop();
            else st.push(c);
        }
        int n=st.size();
        for(int i=n-1; i>=0; i--){
            s[i]=st.top();
            st.pop();
        }
        s.erase(n);
        return s;
    }
};