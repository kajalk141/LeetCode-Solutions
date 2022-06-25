typedef pair<int,int> pii;
typedef long long ll;
ll mod=1e9+7;
class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n=nums.size();
        vector<ll> prefix(n,0), ple(n,-1), nle(n,n);
        prefix[0]=nums[0];
        for(int i=1; i<n; i++) prefix[i]=nums[i]+prefix[i-1];
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
            ll temp=prefix[nle[i]-1];
            if(ple[i]!=-1) temp-=prefix[ple[i]];
            temp=temp*nums[i];
            res=max(res,temp);
        }
        return res%mod;
    }
};