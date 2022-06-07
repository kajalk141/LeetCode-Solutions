class Solution {
public:
    vector<vector<int>> res;
    int n;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        rec(nums,temp);
        return res;
    }
    
    void rec(vector<int> &nums, vector<int> &temp){
        if((int)temp.size()==(int)nums.size()){
            res.push_back(temp);
            return;
        }
        for(int i=0; i<(int)nums.size(); i++){
            bool present=false;
            for(int j=0; j<(int)temp.size(); j++){
                if(nums[i]==temp[j]){
                    present=true;
                    break;
                }
            }
            if(present==false){
                temp.push_back(nums[i]);
                rec(nums,temp);
                temp.pop_back();
            }
        }
        return;
    }
};