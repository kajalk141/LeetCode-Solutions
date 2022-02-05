class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> nge(n,-1);
        stack<pair<int,int>> st;
        st.push({nums[0],0});
        for(long long i=1; i<2ll*n; i++){
            while(!st.empty() && st.top().first<nums[i%n]){
                nge[st.top().second]=nums[i%n];
                st.pop();
            }
            st.push({nums[i%n],i%n});
        }
        return nge;
    }
};     