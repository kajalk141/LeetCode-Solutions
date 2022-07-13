class Solution {
public:
    int countGoodSubstrings(string s) {
        int cnt=0, n=s.size();
        for(int i=0; i<=n-3; i++){
            set<char> st;
            bool flag=1;
            for(int j=i; j<i+3; j++){
                if(st.count(s[j])!=0) flag=0;
                st.insert(s[j]);
            }
            if(flag) cnt++;
        }
        return cnt;
    }
};