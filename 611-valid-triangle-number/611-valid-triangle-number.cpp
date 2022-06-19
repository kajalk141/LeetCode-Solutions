class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size(), res=0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int sum=nums[i]+nums[j];
                int l=j+1, r=n-1, ans=-1;
                while(l<=r){
                    int mid=(l+r)/2;
                    if(nums[mid]<sum){
                        ans=mid;
                        l=mid+1;
                    }
                    else r=mid-1;
                }
                if(ans!=-1) res+= (ans-j);
            }
        }
        return res;
    }
};