# Simple Linked List (eden)

### Introduction

#### Knowledge points: (copy) constructor, deep copy, pointers, dynamic allocation, linked list algorithms, debug methods(GDB or IDE or output debug), memory leak.

#### In this Lab(It used to be a lab), you are going to implement a class named list which is a simple version for the list in stl. You are going to use dynamic memory allocation and pointer operations to finish this project.

### I recommend you to:

* Learn the knowledge points mentioned above.
* Use local compilers to test you program rather than submit your answer to the system time after time.
* Use local debug tools(GDB is recommended) to debug your code, especially for the memory leak problem. I can tell * * you that you will meet runtime error problem if you don't use local debug tools.
* Make use of your paper and pen to have some sketches because it's a good way when you meet list.
 

### Requirements:

#### Finish all the functions which have been declared inside the hpp file.

### Details:  
```
string toString(void) const

Return a visible list using '->' to show the linked relation which is a string like:

1->2->3->4->5->NULL

 

void insert(int position, const int& data)

Add an element at the given position:

example0:

1->3->4->5->NULL

instert(1, 2);

1->2->3->4->5->NULL

example1:

NULL

insert(0, 1)

1->NULL

 

void list::erase(int position)

Erase the element at the given position

1->2->3->4->5->NULL

erase(0)

2->3->4->5->NULL

 ```

### More

#### Happy coding...

### More and More

#### 请大家相信，这道题是一道很重要的题目，c++里面重要的知识点都在里面体现，特别是c++独有的指针。请不要放弃治疗。你们骂我也好，吐槽也好，请大家静下心来好好做这道题目，你会有很大收获。我知道肯定会遇到很多很多问题，希望大家能够平心静气去解决这些问题，比如：
*编译错误，很大一部分同学两节实验课都没能使得程序通过编译（曾经是），原因就是第一对c++语法很不熟悉，域作用符号与命名空间，函数原型等知识理解有偏差，第二对编译器的报错非常陌生，或者不会看编译器的错误信息，关键是要理解。

*浅拷贝很深拷贝，有同学直接对指针进行赋值，却忽略了指针指向的整个链表。打个比方，浅拷贝就是“创建快捷方式”，深拷贝就是真正的“复制粘贴”，浅拷贝中两个指针指向同一块内容，深拷贝则是两个指针有两块数据相同的内存空间。

*new delete运算符不会使用，这个可以参考老师课件。

*赋值运算符重载问题，重载时候没有考虑要将当前(this)对象清除导致内存泄露。或者在拷贝构造函数里面调用赋值运算符时候，没有先初始化head和_size。

*链表算法不熟悉，重要的是画图，一定要画图！指针之间怎么解出链接，怎么重新链接的，一定要通过草稿来理解。还有在链表头部操作和空链表是特殊情况，必须特殊处理。

*内存泄露控制，这是一个很关键的知识。解决内存泄露问题：1. 养成良好的编程习惯，在对原指针赋值的时候，时刻想着会不会出现内存块丢失的问题。 2. 可以维护一个容器，通过重载new和delete运算符来记录堆内存的申请 3. 通过eden系统的提示，慢慢寻找内存错误的源头（需要耐心和细心）
#### 如果有问题请找ta，我们很乐意回答你们问题。

 

#### 请大家多点耐心和细心，静下心来，慢慢调试程序，你所遇到的所有问题都是学习c++路上很珍贵的经验，只有一个一个地解决问题，才能真正提高自己的编程能力。

 

#### 建议写一个经验总结：

*深拷贝的知识。

*赋值运算符为什么要返回 this对象？

*内存泄露怎么处理？

*编程风格怎么注意？

*链表。

### 真正能提高你们的编程能力需要你的耐心和细心。
*All By Source Author---叶嘉祺*
 