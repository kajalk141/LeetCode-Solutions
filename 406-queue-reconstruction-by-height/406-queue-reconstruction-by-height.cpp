class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](auto &a, auto &b){
            if(a[0]==b[0]) return a[1]<b[1];
            return a[0]>b[0];
        });
        int n=people.size();
        vector<vector<int>> res;
        for(auto i:people){
            res.insert(res.begin()+i[1], i);
        }
        return res;
    }
};