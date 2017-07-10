#include "queue.hpp"   

void queue::push(int n) {
  if (isFull()) return;
  storage[rear++] = n;
}

void queue::pop(void) {
  if (isEmpty()) return;
  head++;
}

int queue::front(void ) { 
  if(isEmpty()) return 0;
  return storage[head]; 
}

int queue::back(void) { 
  if(isEmpty()) return 0;
  return storage[rear-1]; 
}

bool queue::isFull(void) { return (rear-head >= max_size-1)? true : false; }

bool queue::isEmpty(void) { return (rear<=head)? true : false; }

void queue::clear(void) { head = rear = 0; }