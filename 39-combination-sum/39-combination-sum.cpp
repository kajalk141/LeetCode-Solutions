class Solution {
  
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        rec(target,0,candidates,curr);
        return res;
    }
    
    void rec(int target, int i, vector<int>& candidates, vector<int> &curr){
        if(target==0){
            res.push_back(curr);
            return;
        }
        for(int x=i; x<candidates.size(); x++){
            if(candidates[x]<=target){
                curr.push_back(candidates[x]);
                rec(target-candidates[x],x,candidates,curr);
                curr.pop_back();
            }
        }
        return;
    }
};