class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p=m-1,q=n-1, i=m+n-1;
        while(p!=-1 && q!=-1){
            if(nums1[p]<=nums2[q]){
                nums1[i]=nums2[q];
                q--; i--;
            }
            else{
                nums1[i]=nums1[p];
                p--; i--;
            }
        }
        while(q!=-1){
            nums1[i]=nums2[q];
            q--; i--;
        }
    }
};