class MyCircularQueue {
public:
    deque<int> dq;
    int sz;
    MyCircularQueue(int k) {
        sz=k;
    }
    
    bool enQueue(int value) {
        if((int)dq.size()==sz) return 0;
        dq.push_back(value);
        return 1;
    }
    
    bool deQueue() {
        if(dq.empty()) return 0;
        dq.pop_front();
        return 1;
    }
    
    int Front() {
        if(dq.empty()) return -1;
        return dq.front();
    }
    
    int Rear() {
        if(dq.empty()) return -1;
        return dq.back();
    }
    
    bool isEmpty() {
        return dq.empty();
    }
    
    bool isFull() {
        return dq.size()==sz;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */