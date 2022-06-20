class Solution {
public:
    int reverse(int x) {
        int sum=0;
        // bool pos=(x>=0?true:false);
        // x=abs(x);
        while(x){
            int r=x%10;
            x/=10;
            if((sum>0&&sum>(INT_MAX-r)/10)||(sum<0&&sum<(INT_MIN-r)/10)) return 0;
            sum=sum*10+r;
        }
        return sum;
    }
};