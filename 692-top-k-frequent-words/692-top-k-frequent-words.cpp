typedef pair<int,string> pis;
class mycomp{
public:
    bool operator() (pis &a, pis &b){
        if(a.first==b.first) return a.second>b.second;
        return a.first<b.first;
    }
};

class Solution {
    struct trie{
        trie *child[26];
        int end=0;
        string word;
    };
    trie *root;
public:
    Solution(){
        root=new trie();
    }
    
    void insert(string s){
        trie *curr=root;
        for(char c:s){
            if(!curr->child[c-'a']) curr->child[c-'a']=new trie();
            curr=curr->child[c-'a'];
        }
        curr->end++;
        curr->word=s;
    }
    
    priority_queue<pis, vector<pis>, mycomp> pq;
    
    void heapify(trie *curr){
        for(int i=25; i>=0; i--){
            if(!curr->child[i]) continue;
            if(curr->child[i]->end>0) pq.push({curr->child[i]->end,curr->child[i]->word});
            heapify(curr->child[i]);
        }
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        for(string word:words) insert(word);
        heapify(root);
        vector<string> res;
        while(k--){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};