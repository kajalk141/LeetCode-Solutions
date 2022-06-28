class MyCircularDeque {
public:
    deque<int> dq;
    int sz;
    MyCircularDeque(int k) {
        sz=k;
    }
    
    bool insertFront(int value) {
        if((int)dq.size()==sz) return 0;
        dq.push_front(value);
        return 1;
    }
    
    bool insertLast(int value) {
        if((int)dq.size()==sz) return 0;
        dq.push_back(value);
        return 1;
    }
    
    bool deleteFront() {
        if(dq.empty()) return 0;
        dq.pop_front();
        return 1;
    }
    
    bool deleteLast() {
        if(dq.empty()) return 0;
        dq.pop_back();
        return 1;
    }
    
    int getFront() {
        return dq.empty()?-1:dq.front();
    }
    
    int getRear() {
        return dq.empty()?-1:dq.back();
    }
    
    bool isEmpty() {
        return dq.empty();
    }
    
    bool isFull() {
        if((int)dq.size()==sz) return 1;
        return 0;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */