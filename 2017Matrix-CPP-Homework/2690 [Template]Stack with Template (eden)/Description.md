# [Template]Stack with Template (eden)

## Descrption
Requirement:

In this assignment, you are required to finish the Stack with Template. Please modify class Stack's declaration and definition so as to finish the validation from main.cpp

Attention: please use template you have learned in the class to finish this assignment and DON NOT add and modify any memeber function and member variable.

Warning: 

1. Do not use Stack in STL.

2. Do not use array of Node to finish the definition of some function.

Extra:

The Stack's declaration with element type "int" is below:

```
class Stack {  
    public:  
        Stack() ;

        Stack(const Stack &stack);

        ~Stack();

        bool empty();

        size_t size() const;

        int top() const;

        void push(int element);

        void pop();

        void swap(Stack& stack);

        void reverse(); /*reverse the elements' order in the stack*/

        void clear();

    private:  
        struct Node {  
            int element;  
            Node* next;  
            Node(int ele, Node *n = NULL) {  
                element = ele;  
                next = n;  
            }  
        };  
        Node *top_node;  
        size_t node_num;  
};
```
*出题人：黎洋*