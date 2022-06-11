class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum=0, n=nums.size();
        for(auto num:nums) sum+=num;
        if(x>sum) return -1;
        if(x==sum) return n;
        sum-=x;
        int temp=0, i=0, len=-1;
        for(int j=0; j<n; j++){
            temp+=nums[j];
            while(temp>sum) temp-=nums[i++];
            if(temp==sum) len=max(len,j-i+1);
        }
        return len==-1?-1:n-len;
    }
};