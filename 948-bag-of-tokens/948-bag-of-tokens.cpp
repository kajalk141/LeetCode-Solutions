class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int n=tokens.size();
        int i=0, j=n-1, score=0, res=0;
        while(i<=j){
            if(power>=tokens[i]){
                power-=tokens[i++];
                res=max(res, ++score);
            }else if(score>0){
                power+=tokens[j--];
                score--;
            }else 
                break;
        }
        return res;
    }
};