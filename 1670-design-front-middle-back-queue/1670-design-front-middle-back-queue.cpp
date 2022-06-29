class FrontMiddleBackQueue {
public:
    deque<int> first,second;
    void a2b(){
        while(first.size()>second.size()){
            second.push_front(first.back());
            first.pop_back();
        }
    }
    void b2a(){
        while(first.size()+1<second.size()){
            first.push_back(second.front());
            second.pop_front();
        }
    }
    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
        first.push_front(val);
        a2b();
    }
    
    void pushMiddle(int val) {
        first.push_back(val);
        a2b();
    }
    
    void pushBack(int val) {
        second.push_back(val);
        b2a();
    }
    
    int popFront() {
        if(first.empty() && second.empty()) return -1;
        if(first.empty()){
            int val=second.front();
            second.pop_front();
            return val;
        }
        int val=first.front();
        first.pop_front();
        b2a();
        return val;
    }
    
    int popMiddle() {
        if(first.empty() && second.empty()) return -1;
        
        int val;
        if(first.size()==second.size()){
            val=first.back();
            first.pop_back();
        }
        else{
            val=second.front();
            second.pop_front();
        }
        return val;
        
    }
    
    int popBack() {
        if(first.empty() && second.empty()) return -1;
        int val=second.back();
        second.pop_back();
        a2b();
        return val;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */