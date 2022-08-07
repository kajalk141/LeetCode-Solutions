class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        int maxi=0;
        char maxchar;
        for(char c:tasks){
            freq[c-'A']++;
            if(freq[c-'A']>maxi){
                maxi=freq[c-'A'];
                maxchar=c;
            }
        }
        int idle=(maxi-1)*n;
        for(char c='A'; c<='Z'; c++){
            if(c==maxchar) continue;
            idle-=min(freq[c-'A'], maxi-1);
        }
        return ((int)tasks.size()+max(0,idle));
        
    }
};