class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int p=0, q=n-1;
        vector<int> res;
        while(p<q){
            int sum=numbers[p]+numbers[q];
            if(sum==target){
                res.push_back(p+1);
                res.push_back(q+1);
                return res;
            }
            if(sum<target) p++;
            else q--;
        }
        return res;
    }
};