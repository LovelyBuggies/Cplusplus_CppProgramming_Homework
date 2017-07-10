# [Operator Overloading]Doubly Linked List

## Introduction

We are going to design a link list class in c++. Again, the knowledge of pointer in c++ is
widely used this time and you have to focus when you are coding.   

## Knowledge

This time, you are going to finish a advanced list which is known as doubly
linked list. Each node of the list have three members: data which is use as
the real storage, next pointer which is used to linked the next node of the
list, prev pointer which is use to linked the previous node.



![](https://upload.wikimedia.org/wikipedia/commons/thumb/5/5e/Doubly-linked-
list.svg/610px-Doubly-linked-list.svg.png)





## Requirements

Finish the member functions below.

Notice that for output functions, the format is as below:

### toString() [1,2,3,4,5]

    
    
    NULL<-1<->2<->3<->4<->5->NULL  
    

### toString() []

    
    
    NULL  
    

### toString() [1]

    
    
    NULL<-1->NULL

No new line is needed;

###  

### void split(int position, list* des1, list* dest2) 2 [1,2,3,4]

[1,2] [3,4]



### list& merge(const list& src1, const list& src2) [1,2,3,4] [5,6,7,8]

[1,2,3,4,5,6,7,8]

###  

### list& remove_if(bool (*condition)(listPointer)); [1,2,3,4,5,6] condition =
`odd number`

[2,4,6]

###  

### list& unique(void) [1,2,2,3,4,4,5,6]

[1,2,3,4,5,6]

###  
list& reverse(void) [1,2,3,4,5,6]

[6,5,4,3,2,1]

## Links
Auto repair tool for annoying Google style:

[传送门](http://clang.llvm.org/docs/ClangFormat.html)

clang-format -i -style=Google CODE_FILES    
*出题人： 叶嘉琪*