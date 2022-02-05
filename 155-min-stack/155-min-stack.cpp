class MinStack {
public:
    stack<long> st;
    long mini;
    MinStack() {
        
    }
    
    void push(int value) {
        // long long value=(long long) val;
        if(st.empty()){
            st.push(value);
            mini=value;
            return;
        }
        if(value>=mini) st.push(value);
        else{
            st.push(2LL*value-mini);
            mini=value;
        }
    }
    
    void pop() {
        if(st.top()<mini){
            mini=2LL*mini-st.top();
        }
        st.pop();
    }
    
    int top() {
        if(st.top()<mini){
            return mini;
        }
        return st.top();
    }
    
    int getMin() {
        return mini;
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