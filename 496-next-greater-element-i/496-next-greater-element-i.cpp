class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size(), m=nums1.size();
        map<int,int> mp;
        // vector<int> nge(n,-1);
        stack<int> st;
        st.push(nums2[0]);
        for(int i=1; i<n; i++){
            while(!st.empty() && st.top()<nums2[i]){
                mp[st.top()]=nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        for(int i=0; i<m; i++){
            nums1[i]=(mp.count(nums1[i])?mp[nums1[i]]:-1);
        }
        return nums1;
    }
};