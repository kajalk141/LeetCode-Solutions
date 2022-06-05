class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        sort(candidates.begin(),candidates.end());
        rec(target,0,candidates,curr);
        return res;
    }
    void rec(int target, int i, vector<int>& candidates, vector<int> &curr){
        if(target==0){
            res.push_back(curr);
            return;
        }
        for(int x=i; x<candidates.size(); x++){
            if(candidates[x]>target) return;
            if(x!=i && candidates[x]==candidates[x-1]) continue;
            if(candidates[x]<=target){
                curr.push_back(candidates[x]);
                rec(target-candidates[x],x+1,candidates,curr);
                curr.pop_back();
            }
        }
        return;
    }
};