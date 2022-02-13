class CustomStack {
public:
    vector<int> v;
    int top=-1, n;
    CustomStack(int maxSize) {
        n=maxSize;
    }
    
    void push(int x) {
        if(top==n-1) return;
        top++;
        v.push_back(x);
    }
    
    int pop() {
        if(top==-1) return -1;
        int num=v[top];
        v.erase(v.begin()+top);
        top--;
        return num;
    }
    
    void increment(int k, int val) {
        for(int i=0; i<min(k,top+1); i++) v[i]+=val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */