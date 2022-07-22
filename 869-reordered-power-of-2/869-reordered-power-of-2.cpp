class Solution {
public:
    long long hash(int n){
        long long res=0;
        while(n>0){
            res+= pow(10, n%10);
            n/=10;
        }
        return res;
    }
    bool reorderedPowerOf2(int n) {
        long long h1=hash(n);
        for(int i=0; i<32; i++){
            if(hash(1<<i)==h1) return 1;
        }
        return 0;
    }
};