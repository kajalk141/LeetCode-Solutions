class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(), [](string &a, string &b){
            int n1=a.size(), n2=b.size();
            if(n1==n2) return a>b;
            return n1>n2;
        });
        return nums[k-1];
    }
};