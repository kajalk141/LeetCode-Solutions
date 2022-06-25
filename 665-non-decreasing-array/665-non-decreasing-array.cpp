class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool done=0;
        stack<int> st;
        st.push(nums[0]);
        for(int i=1; i<(int)nums.size(); i++){
            if(nums[i]<nums[i-1]){
                if(done) return false;
                int cnt=0;
                while(!st.empty() && st.top()>nums[i]){
                    cnt++;
                    st.pop();
                }
                if(cnt>1){
                    nums[i]=nums[i-1];
                }
                done=1;
            }
            else st.push(nums[i]);
        }
        return 1;
    }
};