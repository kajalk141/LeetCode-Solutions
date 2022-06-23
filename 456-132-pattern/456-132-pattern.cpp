class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size(), prev=INT_MIN;
        deque<int> dq;
        for(int i=n-1; i>=0; i--){
            if(!dq.empty() && nums[i]<=dq.back()){
                if(prev>nums[i] && nums[i]<dq.back()) return true;
                else dq.push_back(nums[i]);
            }
            else{
                while(!dq.empty() && nums[i]>dq.back()){
                    prev=dq.back();
                    dq.pop_back();
                }
                dq.push_back(nums[i]);
            }
        }
        return false;
    }
};