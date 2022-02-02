class MinStack {
public:
    vector<int> v;
    int tp=-1, mn=INT_MAX;
    multiset<int> m;
    MinStack() {
        
    }
    
    void push(int val) {
        v.push_back(val);
        tp++;
        m.insert(val);
    }
    
    void pop() {
        int ele=v[tp];
        v.erase(v.begin()+tp);
        m.erase(m.lower_bound(ele));
        tp--;
    }
    
    int top() {
        return v[tp];
    }
    
    int getMin() {
        return *(m.begin());
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */