class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        vector<int> res(2);
        for(int i=0; i<nums.size(); i++){
            int comp=target-nums[i];
            if(mp.find(comp)!=mp.end()){
                res[0]=mp[comp];
                res[1]=i;
                break;
            }
            mp[nums[i]]=i;
        }
        return res;
    }
};