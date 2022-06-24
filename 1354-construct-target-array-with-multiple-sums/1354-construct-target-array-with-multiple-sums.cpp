class Solution {
public:
    bool isPossible(vector<int>& target) {
        long n=target.size(), sum=0;
        priority_queue<int> pq;
        for(int i:target){
            sum+=i;
            pq.push(i);
        } 
        while(1){
            int x=pq.top(); pq.pop();
            sum-=x;
            if(x==1||sum==1) return true;
            if(x<sum||sum==0||x%sum==0) return false;
            x=x%sum;
            sum+=x;
            pq.push(x);
        }
    }
};