class Solution {
public:
    string reverseWords(string s) {
        int i=0, n=s.size();
        while(i<n){
            int j=i, q;
            while(s[j]!=' '&&s[j]!='\0') j++;
            q=j+1;
            j--;
            while(i<=j){
                char temp=s[i];
                s[i]=s[j];
                s[j]=temp;
                i++; j--;
            }
            i=q;
        }
        return s;
    }
};