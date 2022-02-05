class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size(), m=nums1.size();
        map<int,int> mp;
        for(int i=0; i<n; i++) mp[nums2[i]]=i;
        vector<int> nge(n,-1);
        stack<pair<int,int>> st;
        st.push({nums2[0],0});
        for(int i=1; i<n; i++){
            while(!st.empty() && st.top().first<nums2[i]){
                nge[st.top().second]=nums2[i];
                st.pop();
            }
            st.push({nums2[i],i});
        }
        for(int i=0; i<m; i++){
            nums1[i]=nge[mp[nums1[i]]];
        }
        return nums1;
    }
};