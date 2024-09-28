class MyCircularDeque {
public:
    vector<int> deq;
    int K;
    int front;
    int rear;
    int currcount;
    MyCircularDeque(int k) {
        K = k;
        deq = vector<int>(K,0);
        front = 0;
        rear = K-1;
        currcount = 0;
    }
    
    bool insertFront(int value) {
         if(isFull()) return false;

         front = (front-1+K)%K;
         deq[front] = value;
         currcount++;
         return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;

        rear = (rear + 1)%K;
        deq[rear] = value;
        currcount++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;

        front = (front + 1) % K;
        currcount --;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;

        rear = (rear -1 + K) % K;
        currcount --;
        return true;
    }
    
    int getFront() {
        if(currcount == 0) return -1;

        return deq[front];
    }
    
    int getRear() {
        if(currcount == 0) return -1;

        return deq[rear];
    }
    
    bool isEmpty() {
        return currcount == 0;
    }
    
    bool isFull() {
        return currcount == K;
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
