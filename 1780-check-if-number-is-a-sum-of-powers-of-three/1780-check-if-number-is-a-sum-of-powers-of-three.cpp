class Solution {
    
public:
    bool checkPowersOfThree(int n) {
        if(n==1) return 1;
        if(n%3==2) return 0;
        return checkPowersOfThree(n/3);
    }
    
};