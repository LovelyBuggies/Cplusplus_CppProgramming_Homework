# [Template]Review Template and Stack (eden)

## Description
**key points: **

template class and function, stack and queue.

**Description:**

In this assignment, you need to complete Class Stack's declaration and
definition with Template. The different thing is that the Stack is implemented
by two queues.  Following is the example of Stack in integer:

```
class Stack {
  public:
    Stack(); // constructor.
    void push(const int& data); // push operation.
    int pop(); // return the value in the top and pop it out of the stack.
    int top(); // return the value in top.
    int size() const;  // return size of the stack.
    bool empty(); // check whether is empty.

  private:
    queue<int> q1; // two queues.
    queue<int> q2;
    int count; // the number of elements.
};
```

**And you need to define a print function to print the content in the Stack from
top to bottom. The format is: every element is followed by a blank space and
an endl in the end.**

**Extra:**

1. You are not allowed to use any STL except "queue".

2. For more detail, see the codes in main.cpp.

*出题人：黎洋*