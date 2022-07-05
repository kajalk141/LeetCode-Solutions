class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size(), ans=0;
        set<int> st;
        for(int num:nums) st.insert(num);
        for(int x:st){
            if(st.find(x-1)==st.end()){
                int y=x, len=0;
                while(st.find(y++)!=st.end()) len++;
                ans=max(ans,len);
            }
        }
        return ans;
    }
};