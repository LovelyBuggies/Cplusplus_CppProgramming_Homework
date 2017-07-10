# [Classes and Objects]D&A Static Linked List

Introduction

Knowledge points: encapsulation, copy constructor, linked list algorithms, debug methods(GDB or IDE or output debug).

In this Lab, again, you are going to implement a class named static linked list which is based on an fiexed length array storage. You need to figure out the logic inside this.

I recommend you to:

Learn the knowledge points mentioned above. Use local compilers to test you program rather than submit your answer to the system time after time. Use local debug tools(GDB is recommended) to debug your code, especially for the memory leak problem. I can tell you that you will meet runtime error problem if you don't use local debug tools. Make use of your paper and pen to have some sketches because it's a good way when you meet list.

# Knowledge

## Linked List

Read the "Linked lists using arrays of nodes" part.

## Requirements:

Just read the requirements in "simple list"

Note that there are exactly two "list" in the class list. One is the actual list while another is the list to maintain the empty nodes in the storage array. And we use `empty_head` as the head node for the latter.  The operation of the linked list implies the maintenance of the empty nodes.

Source Author: *叶嘉祺*