# [Algorithm] Tree Traverse

## Description

  A right-heavy tree is a binary tree where the value of a node is greater than or equal to the values of the nodes in its left subtree and less than the values of the nodes in its right subtree. A right-heavy tree could be empty.  
	
  Write a program that will create a right-heavy tree from a given input sequence and then traverse the tree and printing the value of the node each time a node is visited using inorder, preorder and postorder traversal.  

  The program should create the nodes in the tree dynamically. Thus, basically the tree can be of any size limited only by the amount of memory available in the computer.  

**Input:**  
  The first number in the input indicates the number of nodes in the tree. Then, the input is followed by the integers comprising the values of the nodes of the tree. （the first node as the root node）

**Output:**  

  The output will be the sequence of node and labeled by the traversal method used, as shown in the sample output below.

**Sample:**  
    
```
     Test Case #1
    
         [Test input]
        +---------------------------------------------------------------------
        |9 5 5 6 3 2 9 3 3 2
        +---------------------------------------------------------------------
    
    
         [stdout output]
        +---------------------------------------------------------------------
        |Inorder: 2 2 3 3 3 5 5 6 9
        |Preorder: 5 5 3 2 2 3 3 6 9
        |Postorder: 2 3 3 2 3 5 9 6 5
        |
        +---------------------------------------------------------------------  
```

## Hints
### 遍历算法

1．先（根）序遍历的递归算法定义：

若二叉树非空，则依次执行如下操作：

⑴ 访问根结点；

⑵ 遍历左子树；

⑶ 遍历右子树。

2．中（根）序遍历的递归算法定义：

若二叉树非空，则依次执行如下操作：

⑴遍历左子树；

⑵访问根结点；

⑶遍历右子树。

3．后（根）序遍历得递归算法定义：

若二叉树非空，则依次执行如下操作：

⑴遍历左子树；

⑵遍历右子树；

⑶访问根结点。


*出题人：黎洋，林剑*
