class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        int req=0, n=heights.size();
        for(int i=1; i<n; i++){
            if(heights[i]<=heights[i-1]) continue;
            pq.push(heights[i]-heights[i-1]);
            req+=heights[i]-heights[i-1];
            while(req>bricks && ladders>0){
                int ele=pq.top();
                pq.pop();
                req-=ele;
                ladders--;
            }
            if(req>bricks) return i-1;
        }
        return n-1;
    }
};