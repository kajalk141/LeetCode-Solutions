class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> left(n,0), right(n,0);
        int leftmax=0, rightmax=0;
        for(int i=0; i<n; i++){
            left[i]=leftmax;
            leftmax=max(leftmax,height[i]);
        }
        for(int i=n-1; i>=0; i--){
            right[i]=rightmax;
            rightmax=max(rightmax,height[i]);
        }
        int res=0;
        for(int i=0; i<n; i++){
            res+= max(0,min(left[i],right[i])-height[i]);
        }
        return res;
    }
};