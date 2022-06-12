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
    int findxor(int n){
        TrieNode *curr=root;
        int second=0;
        for(int i=31; i>=0; i--){
            bool bit=(n&(1<<i));
            if(curr->child[!bit]!=NULL) bit=!bit;
            if(bit) second+=(1<<i);
            curr=curr->child[bit];
        }
        return second;
    }
    int findMaximumXOR(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            insert(nums[i]);
        }
        int res=0;
        for(int i=0; i<nums.size(); i++){
            res=max(res, nums[i]^findxor(nums[i]));
        }
        return res;
    }
};