#include<iostream>
#include<cstddef>
using namespace std;
 template <typename ElementType>
class Stack {
    public:
        Stack() {
            top_node = NULL;
            node_num = 0;
        }
         Stack(const Stack<ElementType> &stack) {
            if (this == &stack) return;
            top_node = NULL;
            node_num = 0;
            if (stack.top_node == NULL) return;
             Node *copy_temp = stack.top_node;
            Node *top_temp = NULL;
            while (copy_temp) {
                if (top_temp == NULL) {
                    top_node = new Node(copy_temp->element);
                    top_temp = top_node;
                } else {
                    top_node->next = new Node(copy_temp->element);
                    top_node = top_node->next;
                }
                copy_temp = copy_temp->next;
            }
            top_node = top_temp;
            node_num = stack.node_num;
        }
         ~Stack() {
            clear();
        }
         bool empty() {
            return (node_num == 0);
        }
         size_t size() const {
            return node_num;
        }
         ElementType top() const {
            return top_node->element;
        }
         void push(ElementType element) {
            if (top_node == NULL) {
                top_node = new Node(element);
            } else {
                Node*temp = new Node(element, top_node);
                top_node = temp;
            }
            ++node_num;
        }
         void pop() {
            if (top_node == NULL) return;
            Node *temp = top_node;
            top_node = top_node->next;
            delete temp;
            --node_num;
        }
         void swap(Stack<ElementType>& stack) {
            Node* temp = top_node;
            top_node = stack.top_node;
            stack.top_node = temp;
            size_t temp_num = node_num;
            node_num = stack.node_num;
            stack.node_num = temp_num;
        }
         void reverse() {
            if (node_num <= 1) return;
             Stack<ElementType> temp;
            while (!empty()) {
                temp.push(top());
                pop();
            }
            swap(temp);
        }
         void clear() {
            while (!empty()) pop();
        }
     private:
        struct Node {
            ElementType element;
            Node* next;
            Node(ElementType ele, Node *n = NULL) {
                element = ele;
                next = n;
            }
        };
        Node *top_node;
        size_t node_num;
};