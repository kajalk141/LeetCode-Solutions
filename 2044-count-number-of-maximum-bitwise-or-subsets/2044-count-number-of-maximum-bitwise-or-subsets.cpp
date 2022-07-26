class Solution {
public:
    int curr=0, all, n, cnt=0;
    int countMaxOrSubsets(vector<int>& nums) {
        n=nums.size();
        for(int i=0; i<n; i++) all=all|nums[i];
        rec(0,nums);
        return cnt;
    }
    
    void rec(int i, vector<int> &nums){
        if(i==n){
            if(curr==all) cnt++;
            return;
        }
        rec(i+1,nums);
        int prev=curr;
        curr=curr|nums[i];
        rec(i+1,nums);
        curr=prev;
    }
};