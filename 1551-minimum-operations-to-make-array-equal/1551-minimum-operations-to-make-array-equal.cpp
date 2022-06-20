class Solution {
public:
    int minOperations(int n) {
        int mid=n, res=0;
        for(int i=1; i<mid; i+=2) res+= mid-i;
        return res;
    }
};