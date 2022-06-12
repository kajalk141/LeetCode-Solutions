class Solution {
    struct TrieNode{
        TrieNode *child[2];
     };
     TrieNode *root;
public:
    Solution(){
        root=new TrieNode();
    }
    void insert(int n){
        TrieNode *curr=root;
        for(int i=31; i>=0; i--){
            bool bit=(n&(1<<i));
            if(curr->child[bit]==NULL) curr->child[bit]=new TrieNode();
            curr=curr->child[bit];
        }
    }
    int findxor(int n, int m){
        TrieNode *curr=root;
        int second=0;
        for(int i=31; i>=0; i--){
            bool bit=(n&(1<<i));
            if(curr->child[!bit]!=NULL) bit=!bit;
            if((second+(1<<i))>m) bit=0;
            if(curr->child[bit]==NULL) return -1;
            if(bit) second+=(1<<i);
            curr=curr->child[bit];
        }
        return second;
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n=queries.size();
        vector<vector<int>> q(n);
        for(int i=0; i<n; i++){
            q[i]={queries[i][1], queries[i][0], i};
        }
        sort(q.begin(), q.end());
        sort(nums.begin(), nums.end());
        vector<int> res(n,0);
        int j=0;
        for(int i=0; i<n; i++){
            while(j<nums.size() && nums[j]<=q[i][0]) insert(nums[j++]);
            int second=findxor(q[i][1], q[i][0]);
            res[q[i][2]]=(second==-1?-1:q[i][1]^second);
        }
        return res;
    }
};