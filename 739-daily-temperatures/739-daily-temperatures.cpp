class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n=t.size();
        vector<int> res(n,0);
        stack<int> st;
        // st.push(0);
        for(int i=0; i<n; i++){
            if(st.empty()){
                st.push(i);
                continue;
            }
            if(t[i]<=t[st.top()]) st.push(i);
            else{
                while(!st.empty() && t[i]>t[st.top()]){
                    res[st.top()]=i-st.top();
                    st.pop();
                }
                st.push(i);
            }
        }
        return res;
    }
};