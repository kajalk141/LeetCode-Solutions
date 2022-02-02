class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0; s[i]!='\0'; i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='[') st.push(s[i]);
            else{
                if(st.empty()==true) return false;
                char c=st.top();
                if(s[i]==')' && c!='(') return false;
                else if(s[i]=='}' && c!='{') return false;
                else if(s[i]==']' && c!='[') return false;
                else st.pop();
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};