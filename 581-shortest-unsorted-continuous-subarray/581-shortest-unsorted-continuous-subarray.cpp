class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        int l=INT_MAX, r=INT_MIN, res, mx=INT_MIN;
        deque<int> dq;
        for(int i=0; i<n; i++){
            if(!dq.empty() && nums[i]>=mx){ 
                // if(r!=INT_MIN && nums[i]==nums[dq.back()] && nums[i]==nums[r]) r++;
                dq.push_back(i);
            }
            else{
                r=max(r,i);
                while(!dq.empty() && nums[i]<nums[dq.back()]){
                    l=min(l,dq.back());
                    dq.pop_back();
                }
                dq.push_back(i);
            }
            mx=max(mx,nums[i]);
        }
        if(l==INT_MAX || r==INT_MIN) res=0;
        else res=r-l+1;
        return res;
    }
};