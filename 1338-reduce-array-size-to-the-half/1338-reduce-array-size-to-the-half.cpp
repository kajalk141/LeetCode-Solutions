class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int> mp;
        for(int x:arr) mp[x]++;
        vector<int> freq;
        for(auto x:mp) freq.push_back(x.second);
        sort(freq.rbegin(), freq.rend());
        int i=0, res=0;
        n/=2;
        while(n>0){
            n-=freq[i++];
            res++;
        }
        return res;
    }
};