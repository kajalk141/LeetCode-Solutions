class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        stack<char> st;
        for(int i=0; i<n; i++){
            if(st.empty()){
                if(s[i]==')'||s[i]=='}'||s[i]==']') return 0;
                st.push(s[i]);
                continue;
            }
            if(s[i]=='('||s[i]=='{'||s[i]=='[') st.push(s[i]);
            else{
                if(s[i]==')' && st.top()!='(') return 0;
                if(s[i]=='}' && st.top()!='{') return 0;
                if(s[i]==']' && st.top()!='[') return 0;
                st.pop();
            }
        }
        return st.empty()?1:0;
    }
};