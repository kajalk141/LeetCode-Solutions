typedef pair<int,int> pii;
typedef long long ll;
int mod=1e9+7;
class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
        int n=nums.size();
        vector<int> ple(n,-1), nle(n,n);
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && nums[st.top()]>nums[i]) st.pop();
            ple[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=0; i<n; i++){
            while(!st.empty() && nums[st.top()]>nums[i]){
                nle[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        ll res=0;
        for(int i=0; i<n; i++){
            res=(res+nums[i]*1ll*(i-ple[i])*(nle[i]-i))%mod;
        }
        return res;
    }
};