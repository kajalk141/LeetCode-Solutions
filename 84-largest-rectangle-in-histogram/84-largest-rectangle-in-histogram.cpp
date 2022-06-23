/*
maintaining a monotonically increasing deque.
[a,b,c,d] a<b<c<d
if e is 
*/
typedef pair<int,int> pii;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        heights.push_back(0);
        int l=-1, ans=0;
        deque<pii> dq;
        for(int i=0; i<=n; i++){
            if(!dq.empty() && heights[i]>=dq.back().first){
                dq.push_back({heights[i],i});
            }
            else{
                int pos=i;
                while(!dq.empty() && heights[i]<dq.back().first){
                    pos=dq.back().second;
                    ans=max(ans, dq.back().first*(i-dq.back().second));
                    dq.pop_back();
                }
                dq.push_back({heights[i],pos});
            }
        }
        return ans;
    }
};