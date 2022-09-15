class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int n=data.size();
        vector<string> bin(n,"");
        for(int i=0; i<n; i++){
            for(int j=7; j>=0; j--)
                bin[i]+=((data[i]&(1<<j))!=0?'1':'0');
        }
        for(int i=0; i<n; i++){
            if(bin[i][0]=='0') continue;
            int cnt=0;
            for(int j=0; j<8 && bin[i][j]!='0'; j++)
                cnt++;
            cnt--;
            if(cnt==0 || cnt>3) return 0;
            while(cnt--){
                i++;
                if(i>=n || !(bin[i][0]=='1' && bin[i][1]=='0'))
                    return 0;
            }
        }
        return 1;
    }
};