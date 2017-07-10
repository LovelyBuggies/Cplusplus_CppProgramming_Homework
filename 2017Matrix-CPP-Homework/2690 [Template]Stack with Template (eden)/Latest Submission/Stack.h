template<typename ElementType>

class Stack {  
public:  
    Stack() {
        node_num = 0;
        top_node = 0;
    }

    Stack(const Stack &stack) {
        node_num = stack.node_num;
        if(node_num == 0) {
            top_node = 0;
            return ;
        }
        top_node = new Node(stack.top_node->element, 0);
        Node *p = this->top_node;
        Node *q = stack.top_node->next;
        while(q) {
            p->next = new Node (q->element, 0);
            p = p->next;
            q = q->next;
        }
    }

    ~Stack() { clear(); }

    bool empty() { return (node_num == 0)? true : false; }

    int size() const { return node_num; }

    ElementType top() const { return top_node->element; }

    void push(ElementType element) {
        node_num++;
        if(this->empty()) {
            top_node = new Node(element, 0);
            return ;
        }
        Node *q = new Node(element, top_node);
        top_node = q;
    }

    void pop() {
        if(empty()) return ;
        Node *q = top_node;
        top_node = top_node->next;
        delete q;
        node_num--;
    }

    void swap(Stack& stack){
        Node* temp = top_node;
        top_node = stack.top_node;
        stack.top_node = temp;
        int temp_num = node_num;
        node_num = stack.node_num;
        stack.node_num = temp_num;
    }

    void reverse() {
        if (node_num <= 1) return;
        Stack temp;
        while(!empty()) 
        {
            temp.push(top());
            this->pop();
        }
        this->swap(temp);
    }

    void clear() {            // pop * size 
        if(empty()) return ;
        Node *p = top_node;
        while(p) {
            Node *q = p->next;
            delete p;
            p = q;
        }
        node_num = 0;
    }

private:  
    struct Node {  
        ElementType element;  
        Node* next;  
        Node(ElementType ele, Node *n = 0) {  
            element = ele;  
            next = n;  
        }  
    };  
    Node *top_node;  
    int node_num;  
};