class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int cnt=0,res=0;
        for(char c:s){
            if(c=='('){
                st.push('(');
                cnt++;
                res=max(res,cnt);
            }
            else if(c==')'){
                st.pop();
                cnt--;
            }
            
        }
        return res;
    }
};