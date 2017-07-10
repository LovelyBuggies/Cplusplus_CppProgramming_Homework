# Simple Tree

### Before Start
#### Last Christmas，you have solved(maybe?) a problem named "圣诞树", so this time, I want you to change it from c to c++.
#### It's no stange that you have to do more work than last Chrismas.
### Here are some tips:
* It's a binary search tree(二叉搜索树)，you can leanrn more about it from google or baidu.
* In this problem, for every node, *it's left chilld is smaller than it and it's right child is bigger than it.*
* Once we input a value which exists in the tree, do nothing.  e.g. For the tree t1 with one node whose value is 1, t1.insert(1) changes no thing.
* If you want to check you tree, you can print it in inorder. (Though you need to print it in preorder in this problem)

### There are different ways to delete a node, to make sure that our output will be the same, you need to delete a node following these rules (suppose now you need to delete p) : 
* 若p有左子树，找到其左子树的最右边的子结点r，用该子结点r来替代p，把r的左孩子
作为r的父亲的右孩子。(假如p的左子树无右子树，用该左子树取代p）
* 若p没有左子树，直接用p的右孩子取代它.

### Hint
Be careful about memory problem(Memory leak, double free, etc. Try to gdb it by yourself).Make good use of those auxiliary functions. Actually you can work out this problem without any auxiliary funcition, you can have a try(if you have enough time).
### Sample Input  
  ```
5
1 2 3 4 5
5
6 7 8 9 10
5
1 2 3 4 5
5
1 2 3 4 5
```
### Sample ouput  *(There will be a space after each number, and a '\n' at the end of line)*
  ```
1 2 3 4 5 
1 2 3 4 5 6 7 8 9 10 
6 7 8 9 10 

6 7 8 9 10 


1 2 3 4 
9 4 3 1 2 6 10 15 17 18 
9 4 3 1 2 5 10 15 17 18 
9 4 3 1 2 5 10 15 17 18 
  ```

