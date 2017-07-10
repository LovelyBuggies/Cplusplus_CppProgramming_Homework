# Stack And Queue(Eden)

### Introduction

#### Welcome to the c++ D&A (data structure and algorithm) topic. This topic will lead us to achieve a set of basic data structures and algorithm based on the c++ features. This time we are going to implement a simple stack as well as a simple queue using encapsulation in c++.

 

## Knowledge

### stack

#### In computer science, a stack is an abstract data type that serves as a collection of elements, with two principal operations: push, which adds an element to the collection, and pop, which removes the most recently added element that was not yet removed. The order in which elements come off a stack gives rise to its alternative name, LIFO (for last in, first out). Additionally, a peek operation may give access to the top without modifying the stack.

### queue

#### In computer science, a queue is a particular kind of abstract data type or collection in which the entities in the collection are kept in order and the principal (or only) operations on the collection are the addition of entities to the rear terminal position, known as enqueue, and removal of entities from the front terminal position, known as dequeue. This makes the queue a First-In-First-Out (FIFO) data structure. In a FIFO data structure, the first element added to the queue will be the first one to be removed. This is equivalent to the requirement that once a new element is added, all elements that were added before have to be removed before the new element can be removed.

 

## Requirement
### For Stack:

#### Your job is to implement the following functions with some other limits:
```
  // you can not push an element when the storage is full 
  void push(int);

  // you can not pop an element when the storage is empty 
  void pop(void);

  // when the stack is empty, you should return 0 
  int peek(void);

  bool isEmpty(void);

  bool isFull(void);

  void clear(void);



  For Queue:

  Your job is to implement the following functions with some other limits:

  // you can not push an element when the storage is full
  void push(int);

  // you can not pop an element when the storage is empty
  void pop(void);

  // when the queue is empty, you should return 0
  int front(void);

  // when the queue is empty, you should return 0
  int back(void);

  bool isFull(void);

  bool isEmpty(void);

  void clear(void);
 
```
### Deep Thinking and Discuss

*1. Why the class queue initialize the storage's size to MAXSIZE+1 rather than MAXSIZE?

*2. What's the disadvantages of the stack and queue in this question?

 

### More

#### If you have any ideas or thoughts about C++ D&A. Just leave a message below or send me a mail.

### Next we will have some dynamic storage practice. I recommend you to review so basic knowledge about pointer and memory allocation about c that you learned it last semester.

### Hint
#### Queue 中初始化的数组的大小为 maxsize+1，真正存储的最大容量仍然为MAX_SIZE. 也就是 capability == MAX_SIZE. 思考这样初始化的用意（循环队列）
*Source Author: 叶嘉祺*