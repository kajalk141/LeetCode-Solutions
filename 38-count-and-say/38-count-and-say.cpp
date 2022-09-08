class Solution {
public:
    string s="";
    void rec(int n){
        if(n==1){
            s+= "1";
            return;
        }
        rec(n-1);
        int cnt=1;
        char num=s[0];
        string res="";
        for(int i=1; s[i]; i++){
            if(s[i]==num) cnt++;
            else{
                res+= to_string(cnt);
                res+= num;
                cnt=1; num=s[i];
            }
        }
        res+= to_string(cnt);
        res+= num;
        s=res;
    }
    string countAndSay(int n) {
        s="";
        rec(n);
        return s;
    }
};