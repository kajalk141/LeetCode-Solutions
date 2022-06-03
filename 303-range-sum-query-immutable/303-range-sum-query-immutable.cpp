class NumArray {
public:
    vector<int> v;
    int n;
    NumArray(vector<int>& nums) {
        n=nums.size();
        v=nums;
        for(int i=1; i<n; i++) v[i]+=v[i-1];
    }
    
    int sumRange(int left, int right) {
        int sum=v[right];
        if(left-1>=0) sum-=v[left-1];
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */