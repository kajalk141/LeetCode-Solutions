class Solution {
    vector<int> v, vv;
    int n;
public:
    Solution(vector<int>& nums) {
        v=nums;
        vv=nums;
        n=nums.size();
    }
    
    vector<int> reset() {
        return v;
    }
    
    vector<int> shuffle() {
        int x=rand()%n, y=rand()%n;
        int temp=vv[x];
        vv[x]=vv[y];
        vv[y]=temp;
        return vv;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */