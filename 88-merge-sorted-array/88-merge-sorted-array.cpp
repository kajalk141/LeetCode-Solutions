class Solution {
    void swap(int &a, int &b){
        int temp=a;
        a=b;
        b=temp;
    }
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0) return;
        int i=0;
        for(i=0; i<m; i++){
            if(nums1[i]<=nums2[0]) continue;
            else{
                swap(nums1[i], nums2[0]);
                sort(nums2.begin(), nums2.end());
            }
        }
        for(i=0; i<n; i++){
            nums1[i+m]=nums2[i];
        }
    }
};