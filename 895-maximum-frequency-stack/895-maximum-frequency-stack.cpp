typedef tuple<int,int,int> t;

class comp{
public:
    bool operator()(t &a, t &b){
        if(get<0>(a)==get<0>(b)) return get<1>(a)<get<1>(b);
        return get<0>(a)<get<0>(b);
    }
};
class FreqStack {
public:
    priority_queue<t, vector<t>, comp> pq;
    map<int,int> mp;
    int cnt=0;
    FreqStack() {
       cnt=0; 
    }
    
    void push(int val) {
        cnt++;
        mp[val]++;
        pq.push({mp[val],cnt,val});
    }
    
    int pop() {
        int n=get<2>(pq.top());
        pq.pop();
        mp[n]--;
        return n;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */