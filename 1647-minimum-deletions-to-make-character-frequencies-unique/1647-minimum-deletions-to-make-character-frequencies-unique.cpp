class Solution {
public:
    int minDeletions(string s) {
        int n=s.size();
        vector<int> freq(26,0);
        for(int i=0; s[i]; i++){
            freq[s[i]-'a']++;
        }
        int res=0;
        set<int> seen;
        for(int i=0; i<26; i++){
            if(freq[i]==0) continue;
            int num=freq[i];
            while(num>0 && seen.find(num)!=seen.end()) num--;
            seen.insert(num);
            res+= freq[i]-num;
        }
        return res;
    }
};