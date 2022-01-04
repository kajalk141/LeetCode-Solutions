class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size(), res=0, start=-1, end=-1;
        for(int i=0; i<n; i++){
            int l=i-1, r=i+1, temp=1;
            while(l>=0 && r<n){
                if(s[l]==s[r]){
                    temp+=2; l--; r++;
                }
                else break;
            }
            if(temp>res){
                res=temp;
                start=++l; end=--r;
            }
        }
        for(int i=0; i<n; i++){
            int l=i, r=i+1, temp=0;
            while(l>=0 && r<n){
                if(s[l]==s[r]){
                    temp+=2; l--; r++;
                }
                else break;
            }
            if(temp>res){
                res=temp;
                start=++l; end=--r;
            }
        }
        string stres="";
        for(int i=start; i<=end; i++) stres+=s[i];
        return stres;
    }
};