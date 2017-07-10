//
// Stack.h
// C++
//
// Created by Nino Leo on 17/5/24.
// Copyright © Nino 2017. All rights reserved.
// 


#include <queue>
#include <iostream>

using namespace std;

template <typename ElementType>
class Stack {
  public:

    // constructor.
    Stack() {
        count = 0;
    }
    
    // destructor.
    ~Stack() {}

    // push operation.
    void push(const ElementType& data) {
        count++;
        main_stack.push(data);
    }

    // return the value in the top and pop it out of the stack.
    ElementType pop() {
        if(count == 0) return 0;
        count--;
        int temp = main_stack.back();
        for(int i = 0; i < count; i++){
            save_stack.push(main_stack.front());
            main_stack.pop();
        }
        main_stack.pop();
        for(int i = 0; i < count; i++){
            main_stack.push(save_stack.front());
            save_stack.pop();
        }
        return temp;
    }

    // return the value in top.
    ElementType top() {
        return main_stack.back();
    }

    // return size of the stack.
    int size() const {
        return count;
    }

    // check whether is empty.
    bool empty() {
        if(count == 0) return true;
        else return false;
    }

  private:
    queue<ElementType> main_stack; // two queues.
    queue<ElementType> save_stack;
    int count; // the number of elements.
};



template <typename ElementType>
void print(Stack<ElementType> t) {
    int capacity = t.size();
    for(int i = 0; i < capacity; i++) {
        cout << t.top() << " ";
        t.pop();
    }
    cout << endl;
}