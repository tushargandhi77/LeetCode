class CustomStack {
public:
    vector<int> stack;
    int top;
    int size;
    CustomStack(int maxSize) {
        stack = vector<int>(maxSize,0);
        top = -1;
        size = maxSize;
    }
    
    void push(int x) {
        if(top >= size-1) return;
        top++;
        stack[top] = x;
    }
    
    int pop() {
        if(top == -1) return -1;
        int pop = stack[top];
        top--;
        return pop;
    }
    
    void increment(int k, int val) {
        int inc = k < size ? k : size;
        for(int i = 0;i<inc;i++){
            stack[i] = stack[i] + val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
