class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int res=0, Q=queries.size();
        vector<int> ans(Q);
        for(int i=0; i<(int)nums.size(); i++) if(nums[i]%2==0) res+=nums[i];
        for(int q=0; q<Q; q++){
            int num=queries[q][0], i=queries[q][1];
            if(nums[i]%2==0) res-=nums[i];
            nums[i]+=num;
            if(nums[i]%2==0) res+=nums[i];
            ans[q]=res;
        }
        return ans;
    }
};