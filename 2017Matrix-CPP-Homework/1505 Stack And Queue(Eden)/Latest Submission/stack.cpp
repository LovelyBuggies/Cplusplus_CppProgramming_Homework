#include "stack.hpp"

void stack::push(int n) {
  if (isFull()) return;
  storage[++top] = n;  
}

void stack::pop(void) {
  if (isEmpty()) return;
  top--;
}

int stack::peek(void) { return storage[top]; }

bool stack::isEmpty(void) { return (top==-1)? true : false; }

bool stack::isFull(void) { return (top == max_size-1)? true : false; }

void stack::clear(void) { top=-1; }