# [algorithm]Max Path Of Tree (eden)

## Descrption
Today, you are invited to learn some methods about tree.

### Max-Path of Tree
Given a binary tree, every node has a weight, then you need to find out the path that can make the total weight of all nodes it go through is the maximum.** The weight is always positive.**
### For Example:
![file](/api/users/image?path=1043/images/1495031293149.png)
![file](/api/users/image?path=1043/images/1495031298608.png)
### About the struct MP::TreeNode
* val: the weight of this node.
* id: the id of this node.
* TreeNode \*left, \*right: the pointers to left-child and right-child of this node.
* TreeNode(int x, int i): the constructor, initialize all the member.

### About the class MP::MaxPath
* max: The answer of the Max-Path-Tree
* MaxPath(): default constructor.
* findMaxPath(TreeNode \*root): find out the best path from the root.


From: *林楚庭*
