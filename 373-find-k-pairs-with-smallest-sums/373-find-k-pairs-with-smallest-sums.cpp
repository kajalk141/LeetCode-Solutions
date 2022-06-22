typedef tuple<int,int,int> t;
typedef pair<int,int> p;
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n1=nums1.size(), n2=nums2.size();
        priority_queue<t, vector<t>, greater<t>> pq;
        pq.push({nums1[0]+nums2[0],0,0});
        set<p> s;
        s.insert({0,0});
        vector<vector<int>> res;
        while(!pq.empty() && k--){
            auto x=pq.top();
            pq.pop();
            int i=get<1>(x), j=get<2>(x);
            vector<int> v={nums1[i], nums2[j]};
            res.push_back(v);
            if(i+1<n1 && s.find({i+1,j})==s.end()){
                pq.push({nums1[i+1]+nums2[j], i+1, j});
                s.insert({i+1,j});
            }
            if(j+1<n2 && s.find({i,j+1})==s.end()){
                pq.push({nums1[i]+nums2[j+1], i, j+1});
                s.insert({i,j+1});
            }
        }
        return res;
    }
};