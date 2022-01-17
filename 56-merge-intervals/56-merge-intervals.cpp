class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        int n=intervals.size();
        for(int i=1; i<n; i++){
            if(intervals[i-1][1]>=intervals[i][0]){
                intervals[i][0]=intervals[i-1][0];
                intervals[i][1]=max(intervals[i][1], intervals[i-1][1]);
            }
            else 
                res.push_back(intervals[i-1]);
        }
        res.push_back(intervals[n-1]);
        return res;
    }
};