class MyCircularQueue {
public:
    vector<int> que;
    int K;
    int front;
    int rear;
    int count;

    MyCircularQueue(int k) {
        K = k;
        que = vector<int>(K,0);
        front = 0;
        rear = K-1;
        count = 0;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;

        rear = (rear + 1) % K;
        que[rear] = value;
        count ++;
        return true;
    } 
    
    bool deQueue() {
        if(isEmpty()) return false;

        front = (front + 1 ) % K;
        count--;
        return true;

    }
    
    int Front() {
        if(isEmpty()) return -1;
        return que[front];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return que[rear];
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == K;
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
