class MyQueue {
public:
    stack<int> one, two;
    MyQueue() {
    }
    void move_to_two(){
        if(two.empty()){
            while(!one.empty()){
                two.push(one.top());
                one.pop();
            }
        }
    }
    void push(int x) {
        one.push(x);
    }
    
    int pop() {
        int ret;
        move_to_two();
        ret = two.top();
        two.pop();
        return ret;
    }
    
    int peek() {
        move_to_two();
        return two.top();
    }
    
    bool empty() {
        return one.empty()&&two.empty();
    }
};
