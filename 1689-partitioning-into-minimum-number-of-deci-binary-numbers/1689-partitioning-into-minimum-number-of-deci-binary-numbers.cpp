class Solution {
public:
    int minPartitions(string s) {
        int res=-1;
        for(char c:s) res=max(res,c-'0');
        return res;
    }
};