// check if you can make 4 subsets with sum=perimeter/4
class Solution {
public:
    long long mask1=0, mask2=0, mask3=0, mask4=0, n;
    bool makesquare(vector<int>& v) {
        n=v.size();
        long long sum=accumulate(v.begin(),v.end(),0);
        if(sum%4!=0) return 0;
        sum/=4;
        mask1=mask2=mask3=mask4=sum;
        sort(v.begin(), v.end());
        return rec(n-1,v);
    }
    
    bool rec(int i, vector<int> &v){
        if(i<0){
            if(mask1==0 && mask2==0 && mask3==0 && mask4==0) return 1;
            return 0;
        }
        
        if(v[i]<=mask1)
        {
            mask1=mask1-v[i];
            if(rec(i-1,v)) return 1;
            mask1=mask1+v[i];
        }
        if(v[i]<=mask2)
        {   mask2=mask2-v[i];
            if(rec(i-1,v)) return 1;
            mask2=mask2+v[i];
        }
        if(v[i]<=mask3)
        {   mask3=mask3-v[i];
            if(rec(i-1,v)) return 1;
            mask3=mask3+v[i];
        }
        if(v[i]<=mask4)
        {   mask4=mask4-v[i];
            if(rec(i-1,v)) return 1;
            mask4=mask4+v[i];
        }
        
        return 0;
    }
};