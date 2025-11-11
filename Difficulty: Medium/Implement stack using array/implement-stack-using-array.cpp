class myStack {
  public:
    vector<int>arr;
    int cap;
    int top;
    myStack(int n) {
        // Define Data Structures
        arr.resize(n);
        cap=n;
        top=-1;
    }

    bool isEmpty() {
        return top==-1;
        // check if the stack is empty
    }

    bool isFull() {
        
        return top==(cap-1);
        // check if the stack is full
    }

    void push(int x) {
        if (isFull()) return;
        arr[++top]=x;
        // inserts x at the top of the stack
    }

    void pop() {
        if (isEmpty()) return;
        --top;
        // removes an element from the top of the stack
    }

    int peek() {
        if (isEmpty()) return -1;
        return arr[top];
        // Returns the top element of the stack
    }
};

