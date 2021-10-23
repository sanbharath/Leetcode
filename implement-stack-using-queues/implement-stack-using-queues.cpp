class MyStack {
public:
    
    queue<int> stack;
   
    MyStack() {
        
    }
    
    void push(int x) {
        queue<int> temp;
        while(stack.size()!=0){
            temp.push(stack.front());
            stack.pop();
        }
        stack.push(x);
        while(temp.size()!=0){
            stack.push(temp.front());
            temp.pop();
        }
    }
    
    int pop() {
        int f = stack.front();
        stack.pop();
        return f;
    }
    
    int top() {
        return stack.front();
    }
    
    bool empty() {
        return stack.size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */