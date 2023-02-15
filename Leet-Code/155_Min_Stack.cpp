class MinStack {
public:
    class StackNode{
        public:
            int val;
            StackNode *next;
            StackNode *pre_min;
            StackNode(int val){
                this->val = val;
                next = pre_min = NULL;
            }
    };
    StackNode *topNode, *minNode;
    MinStack() {
        topNode = minNode = NULL;
    }
    
    void push(int val) {
        StackNode *node = new StackNode(val);
        node->next = topNode;
        topNode = node;
        if(minNode==NULL||minNode->val>val){
            node->pre_min = minNode;
            minNode = node;
        }
    }
    
    void pop() {
        if(topNode==minNode){
            minNode = topNode->pre_min;
        }
        StackNode *temp = topNode->next;
        delete topNode;
        topNode = temp;
    }
    int top() {
        return topNode->val;
    }
    
    int getMin() {
        return minNode->val;
    }
};
