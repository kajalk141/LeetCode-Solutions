class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s=to_string(num), temp="";
        int n=s.size(), sum=0, res=0;
        for(int i=0; i<n; i++){
            if(i<k) temp+=s[i];
            else{
                sum= stoi(temp);
                if(sum!=0) res+= (num%sum==0?1:0);
                temp+= s[i];
                temp[i-k]='0';
            }
        }
        sum= stoi(temp);
        if(sum!=0) res+= (num%sum==0?1:0);
        return res;
    }
};