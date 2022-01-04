class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size(), m=needle.size();
        if(m==0) return 0;
        for(int i=0; i<=n-m; i++){
            bool flag=true;
            for(int j=0; j<m; j++){
                if(haystack[i+j]!=needle[j]){
                    flag=false;
                    break;
                }
            }
            if(flag==true) return i;
        }
        return -1;
    }
};